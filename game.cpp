#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
using namespace std;
int main(int argc, char *argv[]){
	bool ok,extra,start;
	int a[10],i,j,k,n,opt;
	int lifes=3;
	do{
		fflush(stdin);
		system("CLS");
		ok=true;
		extra=true;
		start=false;
		srand(time(NULL));
		j=0;
		do{
			n=rand()%10+1;
			if(j!=0){
				for(i=0;i<j;i++){
					if(a[i]==n){
						ok=false;
						break;
					}else{
						a[j]=n;
						ok=true;
					}
				}
			}else{
				a[j]=n;
			}
			if(ok==true){
				j++;
				ok=false;
			}	
		}while(j<10);
		j=0;
		do{
			system("COLOR 07");
			k=0;
			while((k!=(j+1)) || k==0){
				cout<<"\n\n\n\t"<<a[k]<<endl;
				sleep(1.25);
				system("CLS");
				if(k==0 && j==0){
					break;
				}else{
					k++;
				}
			}
			cout<<endl;
			k=0;
			cout<<"\n\n\n";
			if(j==9){
				cout<<"Last level!\n";
			}
			cout<<"Level "<<j+1<<endl;
			while((k!=(j+1)) || k==0){
				cout<<"-> ";
				cin>>n;
				if(a[k]==n){
					system("COLOR 0A");
					k++;
					ok=true;
					cout<<"OK\n";
					sleep(0.95);
				}else{
					system("COLOR 04");
					cout<<"ERROR!\n";
					sleep(1);
					lifes--;
					ok=false;
					break;
				}
				if(j==0 && k-1==0){
					break;
				}
			}
			if(ok==true){
				j++;
				if(lifes==3){
					system("COLOR 0A");
				}else{
					system("COLOR 06");
				}
				cout<<"\nOK!!!\nlifes "<<char(158)<<" "<<lifes<<endl;
				sleep(1.25);
				system("CLS");
			}else{
				system("COLOR 04");
				cout<<"\nYou have one less life!\nLife "<<char(158)<<" "<<lifes<<endl;
				sleep(1.25);
				system("CLS");
			}
			if(j>=7 && extra==true){
				extra=true;
			}
			if(lifes==0 && j>=7 && extra==true){
				system("COLOR 0A");
				cout<<"\n\n\n\tExtra Life!\n";
				lifes++;
				extra=false;
				sleep(1.25);
				system("CLS");
			}
		}while(j<10 && lifes!=0);
		if(lifes==0){
			system("COLOR 04");
			cout<<"\n\n\n\t\t\tGAME OVER\n";
		}else{
			system("COLOR 0B");
			cout<<"\n\n\n\t\t\tYOU WIN\n";
		}
		cout<<"Score = "<<(lifes+j)*1000<<endl;
		do{
			cout<<"Play Again?\n1.-Yes 2.-No\n";
			cin>>opt;
			if(opt!=1 && opt!=2){
				cout<<"Invalid option!\n";
			}else{
				if(opt==2){
					cout<<"Come back soon!\n";
					start=false;
				}else{
					start=true;
					lifes=3;
				}
			}
		}while(opt!=1 && opt!=2);
	}while(start==true);
	return 0;
}
