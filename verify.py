def myfunc(nums):
    numsmax = nums.copy()
    numsmin = nums.copy()
    max_val = 0
    min_val = 0
    for i in range(len(nums) - 2):
        maxlist = []
        minlist = []
        for j in range(len(numsmax)):
            if len(maxlist) < 3:
                maxlist.append(j)
                maxlist.sort(key=lambda j: numsmax[j], reverse=True)
                minlist.append(j)
                minlist.sort(key=lambda j: numsmin[j])
            else:
                if numsmax[j] > numsmax[maxlist[2]]:
                    maxlist[2] = j
                    maxlist.sort(key=lambda j: numsmax[j], reverse=True)
                elif numsmin[j] < numsmin[minlist[2]]:
                    minlist[2] = j
                    minlist.sort(key=lambda j: numsmin[j])
        max_val += numsmax[maxlist[0]] * numsmax[maxlist[1]] * numsmax[maxlist[2]]
        maxlist.sort()
        del numsmax[maxlist[1]]
        min_val += numsmin[minlist[0]] * numsmin[minlist[1]] * numsmin[minlist[2]]
        minlist.sort()
        del numsmin[minlist[1]]

    return max_val, min_val


# 範例測試
nums = [1, 2, 3, 4, 5]
max_efficiency, min_efficiency = myfunc(nums)
print("最大效益為", max_efficiency) # 預期輸出: 100
print("最小效益為", min_efficiency) # 預期輸出: 38
