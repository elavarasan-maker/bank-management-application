#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;
struct Account { int number; string name; double balance; };
class Bank {
    vector<Account> accounts;
    const string fileName="accounts.txt";
    Account* find(int n){ for(auto& a:accounts) if(a.number==n) return &a; return nullptr; }
    int getInt(const string& msg){ int x; while(cout<<msg && !(cin>>x)){cout<<"Invalid input.\n";cin.clear();cin.ignore(10000,'\n');} cin.ignore(10000,'\n'); return x; }
    double getAmount(){ double x; while(cout<<"Amount (Rs.): " && (!(cin>>x)||x<=0)){cout<<"Enter an amount above zero.\n";cin.clear();cin.ignore(10000,'\n');} cin.ignore(10000,'\n'); return x; }
    void load(){ ifstream f(fileName); Account a; while(f>>a.number>>quoted(a.name)>>a.balance) accounts.push_back(a); }
    bool save(){ ofstream f(fileName); if(!f)return false; for(auto&a:accounts) f<<a.number<<' '<<quoted(a.name)<<' '<<fixed<<setprecision(2)<<a.balance<<'\n'; return bool(f); }
public:
    Bank(){load();}
    void create(){ Account a; a.number=getInt("New account number: "); if(a.number<=0||find(a.number)){cout<<"Invalid/duplicate number.\n";return;} cout<<"Customer name: ";getline(cin,a.name); if(a.name.empty()){cout<<"Name required.\n";return;} a.balance=0; accounts.push_back(a); cout<<(save()?"Account created.\n":"Save failed.\n"); }
    void deposit(){int n=getInt("Account number: ");auto*a=find(n);if(!a){cout<<"Account not found.\n";return;}a->balance+=getAmount();cout<<(save()?"Deposit successful. ":"Save failed. ")<<"Balance Rs. "<<a->balance<<'\n';}
    void withdraw(){int n=getInt("Account number: ");auto*a=find(n);if(!a){cout<<"Account not found.\n";return;}double x=getAmount();if(x>a->balance){cout<<"Insufficient balance.\n";return;}a->balance-=x;cout<<(save()?"Withdrawal successful. ":"Save failed. ")<<"Balance Rs. "<<a->balance<<'\n';}
    void balance(){int n=getInt("Account number: ");auto*a=find(n);if(!a)cout<<"Account not found.\n";else cout<<a->name<<" | Balance: Rs. "<<fixed<<setprecision(2)<<a->balance<<'\n';}
    void list(){if(accounts.empty())cout<<"No accounts.\n";for(auto&a:accounts)cout<<a.number<<" | "<<a.name<<" | Rs. "<<fixed<<setprecision(2)<<a.balance<<'\n';}
    void run(){int c;do{cout<<"\n=== BANK MANAGEMENT ===\n1.Create account\n2.Deposit\n3.Withdraw\n4.Check balance\n5.List accounts\n0.Exit\n";c=getInt("Choice: ");switch(c){case 1:create();break;case 2:deposit();break;case 3:withdraw();break;case 4:balance();break;case 5:list();break;case 0:cout<<"Goodbye.\n";break;default:cout<<"Invalid choice.\n";}}while(c!=0);}
};
int main(){Bank b;b.run();}
