#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int numbers[100];
	int size,sumNumbers=0,findNumber,addIndex,addValue;
	int cntNumber;
	int currentIndex = 0;
	int min,max;
	do{
		printf("*******************MENU**********************\n");
		printf("1.Nhap so phan tu va gia tri cac phan tu\n");
		printf("2.In gia tri cac phan tu dang quan li\n");
		printf("3.In gia tri cac phan tu chan va tinh tong\n");
		printf("4.In gia tri nho nhat va lon nhat trong mang\n");
		printf("5.In phan tu la so nguyen to va tinh tong\n");
		printf("6.Thong ke cac phan tu theo gia tri\n");
		printf("7.Them phan tu theo chi so mang\n");
		printf("8.Thoat\n");
		printf("Lua chon cua ban:");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Nhap vao so phan tu cua mang:");
				scanf("%d",&size);
				for(int i=0;i<size;i++){
					printf("numbers[%d]=",currentIndex);
					scanf("%d",&numbers[currentIndex]);
					currentIndex++;
				}
				break;
			case 2:
				printf("Gia tri cac phan tu trong mang dang quan li:\n");
				for(int i=0;i<currentIndex;i++){
					printf("%d\t",numbers[i]);
				}
				printf("\n");
				break;
			case 3:
				sumNumbers = 0;
				printf("cac phan tu co gia tri le trong mang:\n");
				for(int i=0;i<currentIndex;i++){
					if(numbers[i]%2!=0){
						printf("%d\t",numbers[i]);
						sumNumbers+=numbers[i];
					}
				}
				printf("\nTong cac phan tu le trong mang :%d\n",sumNumbers);
				break;
			case 4:
				min=numbers[0];
				max=numbers[0];
				for(int i=1;i<currentIndex;i++){
					if(min>numbers[i]){
						min=numbers[i];
					}
					if(max<numbers[i]){
						max=numbers[i];
					}
				}
				printf("Gia tri lon nhat :%d-Gia tri nho nhat :%d\n",max,min);
				break;
			case 5:
				sumNumbers = 0;
				printf("Cac so nguyen to trong mang:");
				for(int i=0;i<currentIndex;i++){
					int isPrime = 0;
					if(numbers[i]>=2){
						for(int j=2;j<=sqrt(numbers[i]);j++){
							if(numbers[i]%j==0){
								isPrime = 1;
								break;
							}
						}
					}else{
						isPrime=1;
					}
					if(isPrime==0){
						printf("%d\t",numbers[i]);
						sumNumbers+=numbers[i];
					}
				}
				printf("\nTong cac so nguyen to la:%d\n",sumNumbers);
				break;
			case 6:
				cntNumber=0;
				printf("Nhap vao mot so thong ke trong mang:");
				scanf("%d",&findNumber);
				for(int i=0;i<currentIndex;i++){
					if(numbers[i]==findNumber){
						cntNumber++;
					}
				}
				printf("So phan tu co gia tri %d trong mang la:%d\n",cntNumber,findNumber);
				break;
			case 7:
				printf("Nhap vao gia tri can them trong mang:");
				scanf("%d",&addValue);
				printf("Nhap vao chi so can chen vao mang:");
				scanf("%d",&addIndex);
				if(addIndex<0||addIndex>=99){
					printf("Khong the chen phan tu vao chi so %d\n",addIndex);
				}else{
					if(addIndex==currentIndex){
						numbers[currentIndex]=addValue;
						currentIndex++;
					}else if(addIndex>currentIndex){
						for(int i=currentIndex;i<addIndex;i++){
							numbers[i] = 0;
						}
						numbers[addIndex] = addIndex +1;
						
					}else{
						for(int i=currentIndex;i>addIndex;i--){
							numbers[i] = numbers[i-1];
						}
						currentIndex++;
						numbers[addIndex] = addValue;
						
					}
				}
				break;
			case 8:
				exit(0);
		    default:
		    	printf("Vui long nhap tu 1-8\n");
				
		}
		
	}while(1==1);
}