wuhan = {}
def import_inventory():
    openedFile = open("products.txt")
    whole = []
    nonDupProducts = []
    amounts = []
    for line in openedFile:
        line = line.lower().replace("-"," ").replace("_"," ").strip().split(" ")
        for his in line:
            whole.append(his)
            if his not in nonDupProducts and his.isdigit() == False:
                nonDupProducts.append(his)
    nonDupProducts.sort()
    for prodct in nonDupProducts:
        a = 0
        for element in range(len(whole)):
            if whole[element] == prodct and whole[element + 1].isdigit() == True:
                a += int(whole[element + 1])
        wuhan[prodct] = a
    openedFile.close()
    return wuhan
def sell_product(products):
    sell = input("Please enter products to sell: ")
    sell = sell.lower().replace("_",",").replace("-",",").split(",")
    for i in sell:
        if i.isdigit() == False and i in wuhan and wuhan[i] >= int(sell[sell.index(i) + 1]):
            wuhan[i] -= int(sell[sell.index(i) + 1])
            print(sell[sell.index(i) + 1], i, "sold.")
            if wuhan[i] == 0:
                del wuhan[i]
        elif i.isdigit() == False and i in wuhan and wuhan[i] < int(sell[sell.index(i) + 1]):
            print("There is not enough", i, "in inventory.")
        elif i.isdigit() == False and i not in wuhan:
            print(i, "does not exist in inventory.")
def show_remaining(products):
    if len(products) > 0:
        for elm in products:
            print(elm, ":", products[elm])
    elif len(products) == 0:
        print("Inventory is empty!")
products = import_inventory()
decision = ""
while decision != "3":
  print("*---------------------------")
  print("[1] Sell products")
  print("[2] Show remaining inventory")
  print("[3] Terminate")
  decision = input("Please enter your decision: ")
  print("____________________________")
  if decision == "1":
    sell_product(products)
  elif decision == "2":
    show_remaining(products)
  elif decision == "3":
    print("Terminating...")
  else:
    print("Invalid input!")