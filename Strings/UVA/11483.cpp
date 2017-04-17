#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int i=1;
	while(scanf("%d\n", &n), n){
		printf("Case %d:\n", i);
		printf("#include<string.h>\n#include<stdio.h>\n");
		printf("int main()\n{\n");
		string line;
		while(n--){
			getline(cin,line);
			if(i!=0){
				printf("printf(\"");
				for(int i=0; i< line.size(); i++){
					if(line[i] == '\\'){
						printf("\\\\");
					}else if(line[i] == '\"' ){
						printf("\\\"");
					}else{
						cout << line[i];
					}
				}		
				printf("\\n\");\n");
			}
		}
		printf("printf(\"\\n\");\nreturn 0;\n}\n");
		i++;
	}
	return 0;
}
