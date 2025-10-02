#ifndef THREAD_HELPING_H
#define THREAD_HELPING_H
#include <QLabel>

namespace Thread_helping {
inline bool IsRunning(bool checking, QLabel* statusLabel)
{
    if(checking)
    {
        statusLabel->setText("Button has already passed!");
        return 1;
    }
    else
    {
        statusLabel->clear();
        return 0;
    }
}

inline bool NotRunning(bool checking, QLabel* statusLabel)
{
    if(!checking)
    {
        statusLabel->setText("Button has already passed!");
        return 1;
    }
    else
    {
        statusLabel->clear();
        return 0;
    }
}

}
#endif // THREAD_HELPING_H
