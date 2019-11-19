#include <iostream>
#include <stack>
#include <queue>

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int operation, x;
        bool stack = true, queue = true, priority_queue = true;
        std::stack<int> stack1;
        std::queue<int> queue1;
        std::priority_queue<int> priorityQueue;
        for (int i = 0; i < n; ++i)
        {
            std::cin >> operation >> x;
            if (operation == 1)
            {
                stack1.push(x);
                queue1.push(x);
                priorityQueue.push(x);
            }
            else if (operation == 2)
            {
                if (stack)
                {
                    if (!stack1.empty() && stack1.top() == x)
                        stack1.pop();
                    else
                        stack = false;
                }
                if (queue)
                {
                    if (!queue1.empty() && queue1.front() == x)
                        queue1.pop();
                    else
                        queue = false;
                }
                if (priority_queue)
                {
                    if (!priorityQueue.empty() && priorityQueue.top() == x)
                        priorityQueue.pop();
                    else
                        priority_queue = false;
                }
            }
        }

        if (stack and !queue and !priority_queue)
            std::cout << "stack" << std::endl;
        else if (!stack and queue and !priority_queue)
            std::cout << "queue" << std::endl;
        else if (!stack and !queue and priority_queue)
            std::cout << "priority queue" << std:: endl;
        else if (!stack and !queue and !priority_queue)
            std::cout << "impossible" << std::endl;
        else
            std::cout << "not sure" << std::endl;
    }
    return 0;
}