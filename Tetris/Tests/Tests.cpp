#include <catch2/catch_test_macros.hpp>
#include "ScoreManager.h"

TEST_CASE("Score Calculation for 1 row", "[scoreManager]") {

	ScoreManager scoreManager = ScoreManager();

	scoreManager.calculateScore(1);

	REQUIRE(scoreManager.getScore() == 10);

}

TEST_CASE("Score Calculation for 2 rows", "[scoreManager]") {

	ScoreManager scoreManager = ScoreManager();

	scoreManager.calculateScore(2);

	REQUIRE(scoreManager.getScore() == 25);

}

TEST_CASE("Score Calculation for 3 rows", "[scoreManager]") {

	ScoreManager scoreManager = ScoreManager();

	scoreManager.calculateScore(3);

	REQUIRE(scoreManager.getScore() == 40);

}

TEST_CASE("Score Calculation for 4 rows", "[scoreManager]") {

	ScoreManager scoreManager = ScoreManager();

	scoreManager.calculateScore(4);

	REQUIRE(scoreManager.getScore() == 100);

}

TEST_CASE("Score Calculation for a different amount of rows", "[scoreManager]") {

	ScoreManager scoreManager = ScoreManager();

	scoreManager.calculateScore(48);

	REQUIRE(scoreManager.getScore() == 0);

}