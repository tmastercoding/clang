#include <iostream>
using namespace std;

/*
Prime Province's Employment Problem.

Every year, a new cohort of workers joins the working force and every year a new set of jobs are available.

Prime province has a unique way of classifying the specialisation requirements for a job. 

Each skill is represented by a prime number (2, 3, 5, 7, 11…) and the degree of the skill 
is represented by the exponent of the prime. Thus, a job can represent the requirements 
through a singular number and each individual skill and its degree level 
is made up of the values of prime factorization representation.

For example, a job with a requirement code of 232, has a prime factorization of 2^3 * 29^1.
So it requires one of two skills 2 or 29 at degree level 3 or 1 respectively.

A reminder that candidates only have to fulfil one of the skill requirements.

Similarly, the worker's skills are represented with a singular number, 
which prime factorization represents its skill and degree level.
For example, a worker with a code of 280, has a prime factorization of 2^3 * 5^1 * 7^1.
So they have skill qualifications of 2, 5 and 7 at degree levels 3, 1 and 1 respectively.
So this worker is able to qualify for the earlier mentioned example job 232.

You need to create an algorithm that can match up the workers to jobs based on their skill qualification.
Workers higher up on the list have a higher priority of getting selected for a job.

Input:
Integer J, which represents how many jobs are opening this year
A list R, which represents each requirement code for the jobs and has a length J
Integer W, which represents how many workers are joining this year
A list S, which represents each skill code for the worker and has a length W.

Output:
An integer P, which represents the total sum of each employed worker's skill code.

Hint:
You can find the prime factorization of a number by first dividing by 2
as many times as possible, and then starting at three and attempting to 
divide by every odd number up till the square root of the number. 
Finally, if the last value is greater than 2, that is also a value in the prime factorization.


*/

int main(){


    return 0;
}