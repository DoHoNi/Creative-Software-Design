
#include <iostream>
#include <string>

using namespace std;

int ffresult(int jsu, int gsu, int su);

int cal(string input, int su)
{
    char ic;
    int result =0;
    int minuss =0;
    int gsu=0;//계수
    int jsu=0;//지수
    //int temp_gsu; = 0;
    //int temp_jsu; = 1;
    
    for(int i=0; i<=input.size();)
    {
        ic = input.at(i);
        
        if(ic == 'x')
        {
            if(gsu==0)gsu=1;
            jsu= 1;
        }
        else if(ic=='-')
        {
            minuss = 1;
        }
        else if(isdigit(ic) == true &&i+1!=input.size()  )
        {
            gsu = ic -'0' + (gsu * 10);
        }
        else if(ic == '^')
        {
           
            jsu = 0;
            while(i+1!=input.size() && isdigit(input.at(i+1)) == true )
            {
                i++;
                ic = input.at(i);
                jsu = ic - '0' + (jsu * 10);
                
    
            }
            if(i+1==input.size() )continue;
        }
        else if(ic == '+')
        {
            if(minuss==1) gsu= -gsu;
            
            result += ffresult(jsu, gsu,su);
            jsu=0;
            gsu=0;
            minuss=0;
        }
        if(i==input.size()-1)  //끝에 도달했을때
        {
            if(minuss==1) gsu= -gsu;
            result += ffresult(jsu, gsu,su);
            break;
        }
            
        i++;
    }
    
    return result;
    
}
int ffresult(int jsu, int gsu, int su)
{
    int result=0;
    
    if(jsu == 0)
    {
        return result;
    }
    if(jsu ==1)
    {
    
        return gsu;
    }
    else
    {
        result =1;
        gsu = gsu * jsu;
        for(int i=0; i<jsu-1;i++)
        {
            result =result *su;
        }
        result =result * gsu;
        return result;
    }
};

int main() {
    string input;
    int su;
    
    while(1)
    {
        cin >> input;
        
        if(input == "quit") break;
        else
        {
            cin >> su;
            if(input.find("x")==string::npos)
            {
                cout << 0  << endl;
                continue;
            }
            else
            {
                cout << cal(input,su) <<endl;
                continue;
            }
            
            
        }
    }
    
    
}
