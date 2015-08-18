这是一道二分查找 的变形题目。唯一的关注点就是当str[mid] == ""时的处理，此时仅通过str[mid]=""是无法判断目标是在mid的左边还是右边。所以，我们遍历mid左边的元素找到第一个不是空字符串的元素。
如果mid左边的所有元素都是空字符串，则去掉令start=mid+1；
否则
    找到第一个不是空字符串的元素下标为index
    （1）如果str[index]等于目标正好返回。
    （2）如果str[index]大于目标，则说明目标在str[index]左边，令end = index - 1。
    （3）如果str[index]小于目标，则说明目标在str[mid]右边，令start = mid + 1
    
    
    
/*---------------------------------------
*   日期：2015-08-18
*   作者：SJF0115
*   题目：1009.找出字符串
*   来源：程序员面试金典
*   网址：http://www.nowcoder.com/practice/06f532d3230042769b4d156e963a4f4a?rp=3&ru=/ta/cracking-the-coding-interview
-----------------------------------------*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Finder {
public:
    int findString(vector<string> str, int n, string x) {
        int size = str.size();
        if(size == 0 || n <= 0){
            return -1;
        }//if
        // 采用二分查找
        int start = 0,end = size - 1;
        int mid;
        while(start <= end){
            mid = (end - start) / 2 + start;
            // 遇到空格特殊处理
            if(str[mid] == ""){
                int index = mid;
                while(index >= start && str[index] == ""){
                    --index;
                }//while
                if(index < start){
                    start = mid + 1;
                }//if
                else if(str[index] == x){
                    return index;
                }//else
                else if(str[index] > x){
                    end = index - 1;
                }//else
                else{
                    start = mid + 1;
                }//else
            }//if
            // 非空格
            else{
                // 找到目标
                if(str[mid] == x){
                    return mid;
                }//if
                // 中间值比目标大只能在中间值的左边
                else if(str[mid] > x){
                    end = mid - 1;
                }//else
                // 中间值比目标小只能在中间值的右边
                else{
                    start = mid + 1;
                }//else
            }//else
        }//while
        return -1;
    }
};

int main() {
    Finder s;
    vector<string> vec = {"","","","","","","AECOGS","AOOFYXQ","AQ","AVMMTXNXRA","BAXEVHLYME","BCA","BUV","BVTPMOLHLC","BX","CBDHCOMI","CDWGWW","CLG","CODB","CWKIYFYHNIY","CZA","D","DEMJMHQYMC","DFLYAK","DRR","DVMVXK","EIHULX","EOTCMEXHH","ETYGMD","EXXHWDPS","GNVM","GVEBGEFC","HEFVFXDND","HOUUXMYVC","IDPNQI","IIODZQF","IVPD","JEGHXQCTTNT","JJXNXIYGH","JZBCHVIHK","LIDN","LLKIIAZ","MCBFFHFJBLT","MRTYDDIM","MVWD","N","NJBXRKL","NLEMZIZ","NMMQL","NQQRGMAN","NUO","O","OBC","ONES","OPP","OXOPR","Q","QBZNAE","QCK","QGR","QKLUDC","RWASPGXEUJY","TDDWTG","TER","TTZK","TV","UGUJUEU","UIQYOL","USQENKTCEGJ","UZ","V","VDGRM","VNEFQVOGRYX","VQNFRIPQR","WHLNXPTCPAI","WNYVMOYJBCY","WSZQBUGJO","WVPZVAWYJJ","X","XMTDBDND","XPANBKVAKB","XTPYTK","Y","ZUDJMEVLQJN"};
    string str("TER");
    cout<<s.findString(vec,vec.size(),str)<<endl;
    return 0;
}
