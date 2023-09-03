#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the thin plate spline coefficients
vector<double> thin_plate_spline(const vector<double>& x, const vector<double>& y) {
  // Initialize the coefficients
  vector<double> c(x.size());

  // Loop over all points
  for (int i = 0; i < x.size(); i++) {
    // Calculate the contribution of this point to the coefficients
    double contribution = 0;
    for (int j = 0; j < x.size(); j++) {
      contribution += (x[i] - x[j]) * (x[i] - x[j]) * (y[i] - y[j]);
    }
    c[i] = contribution;
  }

  return c;
}

int main() {
  // Create the input data
  vector<double> x = {1, 2, 3, 4, 5};
  vector<double> y = {2, 4, 6, 8, 10};

  // Calculate the thin plate spline coefficients
  vector<double> c = thin_plate_spline(x, y);

  // Print the coefficients
  for (double c_i : c) {
    cout << c_i << endl;
  }

  return 0;
}

