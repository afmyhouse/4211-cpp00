
class Account
{
	private:

	public:
		typedef Account	t;

		Account(int initial_deposit);
		~Account(void);

		static int getNbAccounts(void);
		static int getTotalAmount(void);
		static int getNbDepositis(void);
		static int getNbWithdrawals(void);

		static void displayAccountInfos(void);

		void makeDeposit(int amount);
		bool makeWithdrawal(int withdrawal);
		bool makeWithdrawal(int withdrawal);
		int checkAmount(void) const;
		void displayStatus(void) const;

	private:

		static int _nbAccounts;
		static int _totalAmount;
		static int _totalNbDeposits;
		static int _totalNbWithdrawals;

		int _accountIndex;
		int _amount;
		int _nbDeposits;
		int _nbWithdrawals;

		Account(void);

};