#ifndef CONTAINERS_H
#define CONTAINERS_H

#include "vector.h"

enum class ContainerType { None, Vector};
enum class Action { None, Generate, Sort };
ContainerType getContainerChoice();
Action getActionChoice();

void performAction(ContainerType containerChoice, Action actionChoice, const vector<int>& sizes);
void runApp();

#endif
