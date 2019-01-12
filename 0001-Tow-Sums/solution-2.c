/* first other solution */
typedef struct HashNode {
    int key;
    int val;
} HashNode;

typedef struct HashMap {
    int size;
    HashNode** storage;
} HashMap;

HashMap* hash_create(int size);
void hash_destroy(HashMap* hashMap);
void hash_set(HashMap* hashMap, int key, int value);
HashNode* hash_get(HashMap* hashMap, int key);

HashMap* hash_create(int size){
    HashMap* hashMap = malloc(sizeof(HashMap));
    hashMap->size = size;
    hashMap->storage = calloc(size, sizeof(HashNode*));
    return hashMap;
}

void hash_destroy(HashMap* hashMap) {
    for(int i=0; i < hashMap->size; i++) {
        HashNode *node;
        if((node = hashMap->storage[i])) {
            free(node);
        }
    }
    free(hashMap->storage);
    free(hashMap);
}

void hash_set(HashMap *hashMap, int key, int value) {
    int hash = abs(key) % hashMap->size;
    HashNode* node;
    while ((node = hashMap->storage[hash])) {
        if (hash < hashMap->size - 1) {
            hash++;
        } else {
            hash = 0;
        }
    }
    node = malloc(sizeof(HashNode));
    node->key = key;
    node->val = value;
    hashMap->storage[hash] = node;
}

HashNode* hash_get(HashMap *hashMap, int key) {
    int hash = abs(key) % hashMap->size;
    HashNode* node;
    while ((node = hashMap->storage[hash])) {
        if (node->key == key) {
            return node;
        }

        if (hash < hashMap->size - 1) {
            hash++;
        } else {
            hash = 0;
        }
    }

    return NULL;
}


int* twoSum(int* nums, int numsSize, int target) {
    HashMap* hashMap;
    HashNode* node;
    int rest, i;
    
    // make the hashMap 2x size of the numsSize
    hashMap = hash_create(numsSize * 2);
    for(i = 0; i < numsSize; i++) {
        rest = target - nums[i];
        node = hash_get(hashMap, rest);
        if (node) {
            int* result = malloc(sizeof(int)*2);
            result[0] = node->val + 1;
            result[1] = i + 1;
            hash_destroy(hashMap);
            return result;
        } else {
            hash_set(hashMap, nums[i], i);
        }
    }
}



/* second other solution */
/* 这个办法虽然高效，但是消耗内存巨大，而且只能解决数据内每个元素不超过50000的元素 */
int* twoSum(int* nums, int numsSize, int target) {
    int _[100001] = {0}, *index_plus_one = _ + 50000;
    for (int i = 0; i < numsSize; i++) {
        int rest = target - nums[i];
        if (index_plus_one[rest]) {
            int *ans = malloc(sizeof(int) * 2);
            ans[0] = i;
            ans[1] = index_plus_one[rest] - 1;
            return ans;
        }
        else
            index_plus_one[nums[i]] = i + 1;
    }
    return NULL;
}




/* 方法不好，占用大量内存，并且循环次数过多  */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *returnSize = malloc(sizeof(int)*2);
    returnSize[0]=returnSize[1]=0;
    int maxPosiNum=0;
    int minNegaNum=0;
    

    // 设置最大值与最小值
    for(int i=0;i<numsSize;i++){
        if(nums[i]>maxPosiNum)
            maxPosiNum=nums[i];
        else if(nums[i]<minNegaNum)
            minNegaNum=nums[i];
    }
    
    int PosiArr[maxPosiNum+1];
    int PosiArr1[maxPosiNum+1]; //if the number appears more than once, then put it in this array
    int NegaArr[-minNegaNum+1];
    int NegaArr1[-minNegaNum+1];

    memset(PosiArr,0,sizeof(int)*(maxPosiNum+1));  // 存正数
    memset(PosiArr1,0,sizeof(int)*(maxPosiNum+1));
    memset(NegaArr,0,sizeof(int)*(-minNegaNum+1));  // 存负数
    memset(NegaArr1,0,sizeof(int)*(-minNegaNum+1));



    for(int j=0;j<numsSize;j++){
        if (nums[j]>=0) {
            (PosiArr[nums[j]]>0)?(PosiArr1[nums[j]]=j+1):(PosiArr[nums[j]]=j+1);
        }
        else{
            (NegaArr[-nums[j]]>0)?(NegaArr1[-nums[j]]=j+1):(NegaArr[-nums[j]]=j+1);
        }
    }


    int lookforNum=0;
    for(int k=0;k<numsSize;k++){
        lookforNum=target-nums[k];
        if(lookforNum>=minNegaNum&&lookforNum<=maxPosiNum){
            if(lookforNum>=0&&PosiArr[lookforNum]>0&&lookforNum!=nums[k]){
                returnSize[0]=(k+1<PosiArr[lookforNum])?k+1:PosiArr[lookforNum];
                returnSize[1]=(k+1>PosiArr[lookforNum])?k+1:PosiArr[lookforNum];
                break;
            }
            else if(lookforNum<0&&NegaArr[-lookforNum]>0&&lookforNum!=nums[k]){
                returnSize[0]=(k+1<NegaArr[-lookforNum])?k+1:NegaArr[-lookforNum];
                returnSize[1]=(k+1>NegaArr[-lookforNum])?k+1:NegaArr[-lookforNum];
                break;
            }
            else if(lookforNum>=0&&PosiArr1[lookforNum]>0&&lookforNum==nums[k]){
                returnSize[0]=PosiArr[lookforNum];
                returnSize[1]=PosiArr1[lookforNum];
                break;
            }
            else if(lookforNum<0&&NegaArr1[-lookforNum]>0&&lookforNum==nums[k]){
                returnSize[0]=NegaArr[-lookforNum];
                returnSize[1]=NegaArr1[-lookforNum];
                break;
            }
        }
    }
    return returnSize;
}



/* other */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* qsort */
typedef struct {
    int idx;
    int data;
} Node;

int compar(const void *p1, const void *p2) {
    if (((Node *)p1)->data < ((Node *)p2)->data) return -1;
    else if (((Node *)p1)->data > ((Node *)p2)->data) return 1;
    else return 0;
}

/*  */
int *twoSum_qsort(int numbers[], int n, int target) {
    int i, j;
    static int ret[2] = { 0, 0 };
    Node *num_nodes = (Node *)calloc(n, sizeof(Node));

    for (i = 0; i < n; i++) {
        num_nodes[i].idx = i + 1;
        num_nodes[i].data = numbers[i];
    }

    qsort(num_nodes, n, sizeof(Node), compar);

    i = 0, j = n - 1;
    while (i < n && j >= 0) {
        if (num_nodes[i].data + num_nodes[j].data == target) {
            ret[0] = num_nodes[i].idx;
            ret[1] = num_nodes[j].idx;
            if (ret[0] > ret[1]) {
                int t = ret[1];
                ret[1] = ret[0];
                ret[0] = t;
            }
            return ret;
        }
        else if (num_nodes[i].data + num_nodes[j].data < target){
            i++;
        }
        else {
            j--;
        }
    }

    return ret;
}

/* hash table */
typedef struct HashNode {
    int val;
    int key;
    struct HashNode * next;
} HashNode;

static inline int hash (int val, int n) {
    int index = val % n;
    return (index > 0) ? (index) : (-index);
}

int *twoSum(int numbers[], int n, int target) {
    static int ret[2] = { 0, 0 };
    int i;

    HashNode **hashtable = (HashNode **)calloc(n, sizeof(HashNode *));

    int idx;
    HashNode *p, *tail;

    // 构建hash表
    for (i = 0; i < n; i++) {
        idx = hash(numbers[i], n);
        //get tail
        p = hashtable[idx];
        tail = NULL;
        while (p != NULL) {
            tail = p;
            p = p->next;
        }
        HashNode *new_node = (HashNode *)calloc(1, sizeof(HashNode));
        new_node->val = numbers[i];
        new_node->key = i;
        new_node->next = NULL;

        if (tail) {
            tail->next = new_node;
        }
        else {
            hashtable[idx] = new_node;
        }
    }

    // 查找hash表
    for (i = 0; i < n; i++) {
        int diff = target - numbers[i];
        idx = hash(diff, n);
        p = hashtable[idx];
        while (p != NULL) {
            if (p->val == diff && p->key != i) {
                ret[0] = p->key;
                ret[1] = i;
                // swap value
                if (ret[0] > ret[1]) {
                    ret[0] = ret[0] ^ ret[1];
                    ret[1] = ret[0] ^ ret[1];
                    ret[0] = ret[0] ^ ret[1];
                }
                return ret;
            }
            p = p->next;
        }
    }

    return ret;
}





