#include <iostream>
#include <stack>
#include <queue>

int main()
{
  int n;
  while (std::cin >> n)
  {
    int operation, x;
    std::stack<int> stack;
    std::queue<int> queue;
    std::priority_queue<int> priority_queue;
    bool canBeAStack = true, canBeAQueue = true, canBeAPQ = true;
    for (int i = 0; i < n; ++i)
    {
      std::cin >> operation >> x;
      if (operation == 1)
      {
        if (canBeAStack)
          stack.push(x);
        if (canBeAQueue)
          queue.push(x);
        if (canBeAPQ)
          priority_queue.push(x);
      }
      else if (operation == 2)
      {
        if (canBeAStack)
          if (stack.top() == x and !stack.empty())
            stack.pop();
        else
          canBeAStack = !canBeAStack;
        if (canBeAQueue)
          if (queue.front() == x and !queue.empty())
            queue.pop();
        else
          canBeAQueue = !canBeAQueue;
        if (canBeAPQ)
          if (priority_queue.top() == x and !priority_queue.empty())
            priority_queue.pop();
        else
          canBeAPQ = !canBeAPQ;
      }
    }
    if (canBeAPQ and !canBeAStack and !canBeAQueue)
      std::cout << "priority queue" << std::endl;
    else if (!canBeAPQ and canBeAStack and !canBeAQueue)
      std::cout << "stack" << std::endl;
    else if (!canBeAPQ and !canBeAStack and canBeAQueue)
      std::cout << "queue" << std::endl;
    else if (!canBeAPQ and !canBeAStack and !canBeAQueue)
      std::cout << "impossible" << std::endl;
    else
      std::cout << "not sure" << std::endl;
  }
  return 0;
}
