#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxsize = 0;
        string temp;
        for(int i = 0 ; i< s.size(); i++){
            int isfound = temp.find(s[i]);
            temp += s[i];
            if(isfound != string::npos){
                temp = temp.substr(isfound+1);
            }
            maxsize = maxsize > temp.size()? maxsize: temp.size();
        }
        return maxsize;
    }
};

// 法二 滑动窗口
// 其实就是一个队列,比如例题中的 abcabcbb，
// 进入这个队列（窗口）为 abc 满足题目要求，当再进入 a，队列变成了 abca，这时候不满足要求。所以，我们要移动这个队列！
// 如何移动？
// 我们只要把队列的左边的元素移出就行了，直到满足题目要求！
// 一直维持这样的队列，找出队列出现最长的长度时候，求出解！
// 时间复杂度：O(n)
/********************模板******************/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_set<char> lookup;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            while (lookup.find(s[i]) != lookup.end()){
                lookup.erase(s[left]);
                left ++;
            }
            maxStr = max(maxStr,i-left+1);
            lookup.insert(s[i]);
    }
        return maxStr;
        
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    //定义两个游标,还有长度,与结果,均初始化为0
        int start(0),end(0),length(0),result(0);
        //只要end<字符串大小
        while(end<s.size())
        {
            //该注释错误		//暂存首个字符char,
            //其实应该是暂存end所指向的那个值,到时候会跟index所指向的值比较
            char tempChar=s[end];
            //定义index,它只用于改变start的指向一般为index+1
            //因为index所处的与end的值相等,则没有统计的必要了
            //for循环只用来判断是否相等
            //
            for(int index=start;index<end;index++)
            {
                //判断是否出现重复字符串
                if(tempChar==s[index])
                {
                    //start++;//这是错误的哦,没有优化呢
                    //如果出现,则将start跳过重复字符index指向的下一字符
                    start=index+1;
                    //保存长度
                    length=end-start;
                    /////////
                    //千万注意,如果相等,则该判断应该结束了
                    break;
                }
            }
            //此时,end向后移动,每一一次,长度+1
            end++;
            length++;
            //返回更新后的length,如果更大,则为它
            result=max(result,length);
        }
        return result;
    }
};

int main(){
    Solution t;
    string s = "aabaab!bb";
    cout << t.lengthOfLongestSubstring(s) << endl;
}