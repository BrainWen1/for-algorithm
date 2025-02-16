#创建基类
class student:
    def __init__(self, name, sex, age):
        self.name = name
        self.sex = sex
        self.age = age
        self.scores = {"chinese": 0, "math": 0, "english": 0}
        self.work = ""

    def print_info(self):
        print("name: " + self.name)
        print("sex:  " + self.sex)
        print("age:  " + self.age)
        print("chinese score: {0}\nmath score: {1}\nenglish score: {2}".format(self.scores["chinese"], self.scores["math"], self.scores["english"]))
        # print(f"chinese score: {self.scores["chinese"]}\nmath score: {self.scores["math"]}\nenglish score: {self.scores["english"]}")
        print(f"work level: {self.work}")

    def change(self, course, score):
        self.scores[course] = score

#继承基类student
class CollegeStudent(student):
    def __init__(self, name, sex, age):
        super().__init__(name, sex, age)
        self.work = "hard"

class PupilStudent(student):
    def __init__(self, name, sex, age):
        super().__init__(name, sex, age)
        self.work = "simple"

#动态语言特性实现多态
def printInfo(student_obj):
    student_obj.print_info()
    print("-" * 20)

#测试(main函数)
wo = CollegeStudent("wenbin", "man", "18") # 创建类对象
printInfo(wo) # 调用打印函数

for course, score in wo.scores.items():
    print(f"{course}: ", end='')
    score = input()
    wo.change(course, score)
print('-' * 20)

printInfo(wo)

# #字符串拼接
# print("Hello " + "Python" + '!')

# #三引号跨行输出
# print('''两个黄鹂鸣翠柳
# 一行白鹭上青天''')
# print()

# #input标准输入
# s = input("please input something: ")
# print(f"this is what you had inputed: {s}")# f:格式化字符串,{varibles}变量

# #if elif
# val = int(input("input a value: "))
# if val == 1:
#     print("1")
# elif 2 <= val <= 5:
#     print("[2,5]")
# else:
#     print("(5,+n)")

# #and or not -> && || !
# val_1 = int(input("NO.1: "))
# val_2 = int(input("NO.2: "))
# if val_1 == 1 and val_2 == 1:
#     print("and")
# elif val_1 == 1 or val_2 == 1:
#     print("or")
# elif not val_1 == 1:
#     print("not")

#列表 -> 数组
# list = ["one", "two"]
# list.append(21)
# print(len(list))
# print(list[1])
# list.remove("two")
# print(len(list))
# print()

# list = [4,7,1,0,12,-4]
# list = sorted(list)
# for num in list:
#     print(num)
# print()

# print(len(list))
# print(max(list))
# print(min(list))

#字典 -> 键值对
# mp = {"NO.1": "brainwen", 
#       "NO.2": "jianghemin",
#       "NO.3": "nobody"}
# if "NO.1" in mp:
#     print("NO.1 is existing")
# else:
#     print("NO.1 isnot existing")
# if "NO.5" in mp:
#     print("NO.5 is existing")
# else:
#     print("NO.5 isnot existing")

# NO_n = input("input NO.4: ")
# mp["NO.4"] = NO_n

# print(len(mp))
# print()

# for elem in mp:
#     print(elem + ": " + mp[elem])
# print()
# for key, val in mp.items():
#     print(key + ': ' + val)
# print()

# del mp["NO.3"]
# print(len(mp))
# print()

#for循环
# array = [1, 6, 0, 3, -2, 9]
# for num in array:
#     print(num, end=' ')
# print('\n')

# print(1,2,3, sep=' and ', end=' ')#print()的参数控制-> sep:分隔符(' ')-> end:结束符('\n')
# print(666)
# print()

# for num in range(5, 10): # [left, right)
#     print(num, end=' ') # 5 6 7 8 9
# print('\n')

# for num in range(1, 100, 2): # 步长为 2
#     print(num, end=' ')
# print()

#while循环
# i = 0
# while i <= 100:
#     print(i, end=' ')
#     i += 1
# print()

#自定义函数
# def add(a, b):
#     return a + b

# x = int(input())
# y = int(input())

# print(add(x, y))

#引入模块
# import statistics
# print(statistics.median([69, 124, -32, 27, 217]))

# from statistics import median
# print(median([69, 124, -32, 27, 217]))