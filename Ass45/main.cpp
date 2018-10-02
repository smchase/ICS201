#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    vector<int> scores;
    int score;
    bool again = true;

    while (again) {
        printf("Enter a bowling score: ");
        scanf("%i", &score);

        score == 999 ? again = false : 0;

        if (score != 999) {
            scores.push_back(score);
        }
    }

    int low = scores[0];
    int hi = scores[0];
    float avg = 0;
    for (int i = 0; i < scores.size(); i++) {
        scores[i] < low ? low = scores[i] : 0;
        scores[i] > hi ? hi = scores[i] : 0;
        avg += scores[i];
    }
    avg /= scores.size();

    printf("\nLowest: %i\nHighest: %i\nAverage: %f\n", low, hi, avg);
}
