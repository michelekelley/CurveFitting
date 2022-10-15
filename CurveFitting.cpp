#include <iostream>
#include <vector>
#include <numeric>

auto linearFit(std::vector<double> x, std::vector<double> y) {

    int n = x.size();
    double xSum = std::accumulate(x.begin(), x.end(), 0);
    double ySum = std::accumulate(x.begin(), x.end(), 0);
    double xxSum = 0;
    double xySum = 0;

    
    for (int i = 0; i < n; i++) {
        xxSum += x[i] * x[i];
        xySum += x[i] * y[i];
    }

    double slopeVal = (n * xySum - xSum * ySum) / (n * xxSum - xSum * xSum);
    double yInterceptVal = ySum / n - slopeVal * xSum / n;

    std::vector<double> solution = { slopeVal, yInterceptVal };
    return solution;
}





int main()
{
    std::vector<double> xVals = { 1,2,3,4,5 };
    std::vector<double> yVals = { 1.1,2.4,3,4.7,6};

    auto answer = linearFit(xVals, yVals);

    std::vector<double> fitY;

    std::cout << "Slope: " << answer[0] << std::endl;
    std::cout << "y-Intercept: " << answer[1] << std::endl;
    std::cout << "   " << std::endl;

    std::cout << "{" << "Fitted Value" << ", " << "True Value" <<"}" << std::endl;
    for (int i = 0; i < xVals.size(); i++) {
        fitY.push_back(xVals[i] * answer[0] + answer[1]);
        std::cout << "{"<<fitY[i] <<"," << yVals[i] <<"}"<< std::endl;
    }

}