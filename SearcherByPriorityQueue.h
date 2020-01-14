//
// Created by nerya on 13/01/2020.
//

#ifndef UNTITLED2_SEARCHERBYPRIORITYQUEUE_H
#define UNTITLED2_SEARCHERBYPRIORITYQUEUE_H

#include "BackTraceSearcher.h"
#include <set>

template<class Solution, class T>
class SearcherByPriorityQueue : public BackTraceSearcher<Solution, T> {
protected:
    class ComparatorByCost {
    public:
        bool operator()(State<T> *leftSide, State<T> *rightSide) {
            return leftSide->getCost() < rightSide->getCost();
        }
    };

    //maybe the member itself need to move into private section, depends on
    multiset<State<T> *, ComparatorByCost> openList;
    /*priority_queue<State<T>*, vector<State<T>*>, ComparatorByCost> openPriorityQueue;*/
    vector<State<T> *> closedList;

    virtual State<T> *popOpenList() {
        this->increaseNumberOfNodesEvaluated();
        auto iter = openList.begin();
        State<T> *result = *iter;
        openList.erase(iter);
        return result;
    }

    virtual unsigned long getOpenListSize() {
        return openList.size();
    }

    virtual void addToOpenList(State<T> *current) {
        openList.insert(current);
    }

    virtual void addToCloseList(State<T> *current) {
        closedList.push_back(current);
    }

    virtual bool doWeHaveThisNodeInOpenList(State<T> *current) {
        for (auto state : openList) {
            if (*current == *state) {
                return true;
            }
        }
        return false;
    }

    virtual bool doWeHaveThisNodeInClosedList(State<T> *current) {
        for (auto node : closedList) {
            if (*current == *node) {
                return true;
            }
        }
        return false;
    }

    void updateCostItemInOpenList(State<T> *item, State<T> *current) {
        if (item->getCost() > current->getCost()) {
            openList.erase(item);
            delete item;
            openList.insert(current);
        }
    }

    void updateStatePriority(State<T> *current) {
        bool wasFound = false;
        for (auto item : openList) {
            if (*item == *current) {
                wasFound = true;
                updateCostItemInOpenList(item, current);
                break;
            }
        }
        if (!wasFound) {
            openList.insert(current);
        }
    }

    virtual void deleteEverything() {
        openList.clear();
        closedList.clear();
    }

public:
    virtual Solution search(Searchable<T> *searchable) = 0;

    virtual ~SearcherByPriorityQueue() {}
};

#endif //UNTITLED2_SEARCHERBYPRIORITYQUEUE_H
