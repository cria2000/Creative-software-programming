using namespace std;
class WorldClock{
	public:
		void Tick(int seconds=1);
		bool SetTime(int hour, int minute, int second);

		int hour() const;
		int minute() const;
		int second() const;

	private:
		int _hour;
		int _minute;
		int _second;
};
ostream& operator<<(ostream& os, const WorldClock& c);
istream& operator>>(istream& is, WorldClock& c);
string* split(string& str, const string& delim);
