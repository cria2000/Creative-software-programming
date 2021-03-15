#include<vector>
#include<iostream>
class SortedArray{
	public:
		SortedArray();
		~SortedArray();

		void AddNumber(int num);

		std::vector<int> GetSortedAscending() const;
		std::vector<int> GetSortedDescending() const;
		int GetMax() const;
		int GetMin() const;

	private:
		std::vector<int> numbers_;};

