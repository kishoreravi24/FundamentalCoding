#include<bits/stdc++.h>
int main(){
    std::vector<std::string> words={"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    std::vector<std::string> secondTestcase={"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth=20;
    
    std::vector<std::pair<std::string,int>> wordsLen;
    for(std::string it:words){
        wordsLen.push_back({it,it.size()});
    }
    
    int initializr_count=0,x=0,customized_size=maxWidth;
    std::string customized_string="";
    std::vector<std::string> result;
    for(int i=0;i<wordsLen.size();i++){
        if(initializr_count==0&&wordsLen[i].second+1<=customized_size){
            if(wordsLen[i].second<customized_size){
                customized_size-=wordsLen[i].second;
                customized_string+=wordsLen[i].first;
                initializr_count++;
            }
        }else if(initializr_count!=0&&wordsLen[i].second+1<=customized_size){
            customized_size-=wordsLen[i].second+1;
            customized_string+=" ";
            customized_string+=wordsLen[i].first;
        }else{
            //eg: for line 1what_must_be , customized_size = 4 , i=3
            int extraPadding = customized_size/2;
            int space_calc[words.size()];
            // if there is space
            for(int i=0;i<customized_string.size();i++){
                if(customized_string[i]==' '){
                    space_calc[x++]=i;
                }
            }
            if(x!=0){
                if(x==1){
                    customized_string.insert(space_calc[0],customized_size,' ');
                }else{
                    for(int i=0;i<x;i++){
                        if(i==0){
                            customized_string.insert(space_calc[i],extraPadding,' ');
                        }else{
                            customized_string.insert(space_calc[i]+(i*extraPadding),extraPadding,' ');
                        }
                    }
                }
            }else{
                customized_string.insert(customized_string.size(),customized_size,' ');
            }
            //eg: what__must__be
            result.push_back(customized_string+",");
            // reset line
            customized_string.clear();
            customized_string=wordsLen[i].first;
            x=0;
            customized_size=maxWidth;
            customized_size-=wordsLen[i].second;
        }
    }
    if(customized_size!=0){
        customized_string.insert(customized_string.size(),customized_size,' ');
        result.push_back(customized_string);
    }
    for(std::string it:result){
        std::cout<<it<<"\n";
    }
}