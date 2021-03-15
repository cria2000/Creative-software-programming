class Account{
public:
	int id;
	int balance;};
class Account_admin{
public:
	int account_num;
	Account a[10];
	void deposit(int num, int amount);
	void withdraw(int num, int amount);
	void transfer(int num, int num_t, int amount);
	void check_balance(int num);};




