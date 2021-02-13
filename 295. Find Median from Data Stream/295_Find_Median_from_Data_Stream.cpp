// https://leetcode.com/problems/find-median-from-data-stream/
#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;
    int maxCount =0, minCount =0;
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        int temp;
        
        if(this->maxCount==0 && this->minCount==0){// when heaps are empty
            this->maxH.push(num);
            this->maxCount += 1;            
        }else if(num< this->maxH.top()){// wants to go left into maxHeap
            if(this->maxCount == (this->minCount)+1){
                temp = this->maxH.top();
                this->maxH.pop();
                this->minH.push(temp);
                this->minCount += 1;
                this->maxH.push(num);
            }else{//this->maxCount == this->minCount
                this->maxH.push(num);
                this->maxCount += 1;            
            }
        }else if(this->maxH.top()< num && num<this->minH.top()){// wants to stay in the middle
            if(this->maxCount == (this->minCount)+1){
                this->minH.push(num);
                this->minCount += 1;            
            }else{//this->maxCount == this->minCount
                this->maxH.push(num);
                this->maxCount += 1;            
            }
        }else if(num> this->minH.top()){// wants to go right into minHeap
            if(this->maxCount == (this->minCount)+1){
                this->minH.push(num);
                this->minCount += 1;            
            }else{//this->maxCount == this->minCount
                temp = this->minH.top();
                this->minH.pop();
                this->maxH.push(temp);
                this->maxCount += 1;
                this->minH.push(num);
            }
        }
    }
    
    double findMedian() {
        double median;

        if(this->maxCount == this->minCount){
            median = (this->maxH.top() + this->minH.top())/2;
            cout<<median<<" ";
        }else{
            median = this->maxH.top();
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */