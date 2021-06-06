#include <iostream>
#include <memory>
#include <chrono>

class Timer
{
  public:
  Timer(){
    m_StartPoint = std::chrono::high_resolution_clock::now();
  }

  ~Timer(){
    stop();
  }

  void stop(){
    auto endPoint = std::chrono::high_resolution_clock::now();

    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartPoint).time_since_epoch().count();

    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endPoint).time_since_epoch().count(); 

    auto duration = end - start;
    double ms = (duration * 0.0001);
    std::cout<< "Completed in " << ms << " ms" <<std::endl;   
  }

  private:
  std::chrono::time_point<std::chrono::high_resolution_clock> m_StartPoint;
};

uint32_t fib(int n){
  if(n == 1 || n==2) return 1;
  return fib(n-1) + fib(n-2);
}

uint32_t fib_2(int n, int* memo){
  if(memo[n]!= 0) return memo[n];
  uint32_t result;
  if(n == 1 || n==2) result = 1;
  else{
    result = fib_2(n-1, memo)+ fib_2(n-2, memo);
  }
  memo[n] = result;
  return result;
}

uint32_t fib_3(int n){
  uint32_t arr[n];
  arr[0] = 1;
  arr[1] = 1;
  for(int i = 2; i<n; i++){
    arr[i] = arr[i-1] + arr[i-2];
  }
  return arr[n-1];
}
int main() {
  std::cout << "Program Started!\n";
  const int N = 35;
  // NonOptimized Fibonacci series 
  std::cout<<"\n======== NonOptimized Recursive =====\n"<<std::endl;
  {
    Timer timer;
    uint32_t result =fib(N);
    std::cout << "Result of Fibonacci upto "<< N << " = " << result << std::endl;
  }
  // Optimized recursive approach
  std::cout<<"\n======== Recursive with memoization =====\n"<<std::endl;
  {
    Timer timer;
    int memo[N+1] = {0};
    uint32_t result = fib_2(N, memo);
    std::cout << "Result of Fibonacci upto "<< N << " = " << result << std::endl; 
  }
  // Bottoms-up approch
  std::cout<<"\n======== Bottoms-Up Approach =========\n"<<std::endl;
  {
    Timer timer;
    uint32_t result = fib_3(N);
    std::cout << "Result of Fibonacci upto "<< N << " = " << result << std::endl;
  }

  std::cout << "Program Finished!\n";
}
