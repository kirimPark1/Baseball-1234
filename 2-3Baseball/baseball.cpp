#include <stdexcept>
#include <string>
using namespace std;

struct Result
{
	bool solved;
	int strikes;
	int balls;
};
class BaseBall
{
public:
	explicit BaseBall(const string& question)
		: question(question) {}

	bool isIncludeChar(string guessNumber)
	{
		for(char ch : guessNumber)
		{
			if (ch >= '0' && ch <= '9') continue;
			return true;
		}
		return false;
	}
	bool isDuplicatedNumber(string guessNumber)
	{
		return guessNumber[0] == guessNumber[1] ||
			guessNumber[0] == guessNumber[2] ||
			guessNumber[1] == guessNumber[2];
	}

	void assertIllegalArgument(string guessNumber)
	{
		if (guessNumber == "")
			throw std::invalid_argument("값을 넣어야함");
		if (guessNumber.length() !=3)
		{
			throw std::invalid_argument("자리수 오류");
		}
		if(isIncludeChar(guessNumber))
		{
			throw std::invalid_argument("숫자로만 구성되어 있지 않음.");
		}
		if (isDuplicatedNumber(guessNumber))
		{
			throw std::invalid_argument("중복수 금지");
		}
	}

	int getStrikeCount(string guessNumber)
	{
		int scnt = 0;
		for (int i = 0; i < 3; i++)
		{
			int f = 0;
			int t = 0;
			int index = question.find(guessNumber[i]);
			if (index == -1)continue;
			if (index != i)continue;
			scnt++;
		}
		return scnt;
	}

	int getBallCount(string guessNumber)
	{
		int bcnt = 0;
		for (int i = 0; i < 3; i++)
		{
			int f = 0;
			int t = 0;
			int index = question.find(guessNumber[i]);
			if (index == -1)continue;
			if (index == i)continue;
			bcnt++;
		}
		return bcnt;
	}

	bool isSolved(string guessNumber)
	{
		return guessNumber == question;
	}

	Result getGuessResult()
	{
		return { true, 3, 0 };
	}

	Result createUnSolvedResult(string guessNumber)
	{
		int scnt = 0;
		int bcnt = 0;
		bool sovled = false;
		scnt = getStrikeCount(guessNumber);
		bcnt = getBallCount(guessNumber);
		return { sovled, scnt, bcnt };
	}

	Result guess(string guessNumber)
	{
		
		assertIllegalArgument(guessNumber);
		if (isSolved(guessNumber))
		{
			return getGuessResult();
		}
		return createUnSolvedResult(guessNumber);
	}
private:
	string question;
};