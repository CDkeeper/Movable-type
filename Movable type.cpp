#include<iostream>
#include<cstring>
using namespace std;
const int N=205;
char t[7];
char n[N];
int cnt;
int cheak[300]; //48,57
int num_of2or5,num_of6or9;
int main() {
	cin>>t;
	cin>>n;
	for(int i=0; i<strlen(n); i++) {
		if(n[i]=='2'||n[i]=='5') num_of2or5++;
		//cheak['2']++,cheak['5']++;
		else if(n[i]=='6'||n[i]=='9') num_of6or9++;
		// cheak['6']++,cheak['9']++;
		else cheak[n[i]]++;
	}
	int aim_l=strlen(t),hav_no=0,is_2or5=0,is_6or9=0;
	char tmp;
	while(1) {
		for(int i=0; i<aim_l; i++) {
			tmp=t[i];
			if(tmp=='2'||tmp=='5') is_2or5=1;
			else if(tmp=='6'||tmp=='9') is_6or9=1;
			if(is_2or5==0&&is_6or9==0) {
				if(cheak[tmp]==0) {
					hav_no=1;
					break;
				} else cheak[tmp]--;
			} else if(is_2or5==1&&is_6or9==0) {
				if(num_of2or5==0) {
					hav_no=1;
					break;
				} else {
					num_of2or5--;
					is_2or5=0;
				}
			} else if(is_2or5==0&&is_6or9==1) {
				if(num_of6or9==0) {
					hav_no=1;
					break;
				} else {
					num_of6or9--;
					is_6or9=0;
				}
			}
		}
		if(hav_no==0)
		cnt++;
		if(hav_no==1)
			break;
	}
	cout<<cnt;
	return 0;
}
