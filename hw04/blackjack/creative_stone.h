
#include <string>
#include <map>
using namespace std;

class CreativeStone
{
public:
    void add(string name,int hp,int power);
    void foeadd(string name,int hp,int power);
    bool attack(string _name1,string _name2);
    void burn(int _damage);
    bool burn(string name,int _damage);
    void print();
    
private:
    map<string,pair<int,int> >our,there;
};