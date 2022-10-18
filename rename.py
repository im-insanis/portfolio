import os

file_path = '/Users/ijieun/2_2_수업/자료구조실습/dataimg'
file_names = os.listdir(file_path)
print(file_names)

i = 1
for name in file_names:
    src = os.path.join(file_path, name)
    dst = str("sample{}".format(i)) + '.jpeg'
    dst = os.path.join(file_path, dst)
    os.rename(src, dst)
    i += 1