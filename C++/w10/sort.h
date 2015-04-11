#include <cstring>

using namespace std;

template<typename T>
void sort(T a, int n){
int i,j,tmp;
	for(i=0;i<n;i++){
		for(j=i+1;j<n-1;j++){
		
			if(a[i]>a[j])
				{
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
				}
		}
	}
}

template<> // explicit specialization
void sort(char* a[], int n) {
	int i,j;
	char * tmp;
	for(i=0;i<n;i++)
		{
			for(j=i+1;j<n-1;j++)
				{
					if(strcmp(a[i],a[j])>0)
						{
							tmp=a[i];
							a[i]=a[j];
							a[j]=tmp;
						}
				}
		}
}