class Bank {
private:
    vector<long long> accounts;

    bool valid(int a) {
        return a >= 1 && a <= accounts.size();
    }
public:
    Bank(vector<long long>& balance) {
        this -> accounts = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(!valid(account1) || !valid(account2) || accounts[account1-1] < money) return false;
        accounts[account1-1] -= money;
        accounts[account2-1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(!valid(account)) return false;
        accounts[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!valid(account) || accounts[account-1] < money) return false;
        accounts[account-1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */