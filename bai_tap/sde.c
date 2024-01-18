#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]){
    if(argc !=4){
        printf("Error!");
        return 1;
    }
    double a = atof(argv[1]),
    b = atof(argv[2]),
    c = atof(argv[3]);

    if(a == 0){
        if(b == 0){
            if(c == 0){
                printf("Phuong trinh co vo so nghiem");
            }else{
                printf("Phuong trinh vo nghiem");
            }
        }else{
            printf("Phuong trinh co nghiem x = %f", -c/b);
        }
    }else{
        double denta = b*b - 4*a*c;
        if(denta > 0){
            double x1 = (-b+sqrt(denta))/(2*a),
                x2 = (-b-sqrt(denta))/(2*a);
            printf("Phuong trinh co 2 nghiem x1 = %f, x2 = %f", x1, x2);
        }
        if(denta == 0 ){
            printf("Phuong trinh co nghiem kep x1 = x2 = %f", -b/(2*a));
        }
        if(denta < 0){
            printf("Phuong trinh vo nghiem");
        }
    }
}