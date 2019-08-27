import xlrd
import random
from xlutils.copy import copy
import xlutils
# https://github.com/python-excel/xlrd
# https://xlrd.readthedocs.io/en/latest/api.html


def test1():
    file = xlrd.open_workbook(filename=r'../file/1.xlsx')
    print(file.sheet_names())
    # 获取工作表的名称
    table = file.sheets()[0]
    # 通过索引顺序获取
    table = file.sheet_by_index(sheetx=0)
    # 通过索引顺序获取
    table = file.sheet_by_name(sheet_name='Sheet1')
    # 通过名称获取
    print("{0} {1} {2}".format(table.name, table.nrows, table.ncols))
    # 打印工作表的名称，表的总行数，表的总列数
    print("Cell A18 is {0}".format(table.cell_value(rowx=17, colx=0)))
    # 打印单元格的值


def test2():
    x = random.random()
    x = round(number=x, ndigits=1)
    print(x)


def main():
    file = xlrd.open_workbook(filename='../file/1.xlsx')
    table = file.sheets()[0]
    wb = copy(wb=file)
    for i in range(1, table.nrows):
        x = random.uniform(0.1, 0.5) + 29
        wb.get_sheet(0).write(i, 2, round(number=x, ndigits=1))
    wb.save('../file/2.xls')


if __name__ == '__main__':
    main()
