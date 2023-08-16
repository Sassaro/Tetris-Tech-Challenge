#pragma once
#ifndef __SCORE_MANAGER_H__
#define __SCORE_MANAGER_H__

class ScoreManager {

private:
	int score = 0;

public:

	ScoreManager();

	~ScoreManager();

	int calculateScore(int linesCompleted);

	void printScore();

	int getScore();

};
#endif // !__SCORE_MANAGER_H__