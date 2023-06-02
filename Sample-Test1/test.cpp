#include "pch.h"
#include "../2-3Baseball/baseball.cpp"
class BaseballGame : public testing::Test
{
public:
	BaseBall baseball{"123"};
};
TEST_F(BaseballGame, InvalidArgument) {
	EXPECT_THROW(baseball.guess(""), std::invalid_argument);
	EXPECT_THROW(baseball.guess("1543"), std::invalid_argument);
	EXPECT_THROW(baseball.guess("1v3"), std::invalid_argument);
	EXPECT_THROW(baseball.guess("121"), std::invalid_argument);
}

TEST_F(BaseballGame, PerfectMatch) {
	Result result = baseball.guess("123");
	EXPECT_EQ(true, result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballGame, MissMatch) {
	Result result = baseball.guess("789");
	EXPECT_EQ(false, result.solved);
	EXPECT_EQ(0, result.strikes);
	EXPECT_EQ(0, result.balls);
}