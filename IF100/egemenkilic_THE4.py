whole = []
openedFile = open("products.txt")
for line in openedFile:
    line = line.lower().strip()
    whole.append(line.split("-"))
x = []
for i in whole:
    for l in i:
        x.append(l.split("_"))
items = {}
for s in x:
    for m in s:
        if m.isdigit() == False and m not in items:
            items[m] = 0
wubba = []
for p in x:
    for f in p:
        wubba.append(f)
test = []
for h in items:
    jiba = 0
    for c in range(len(wubba)):
        if h == wubba[c]:
            jiba += int(wubba[c + 1])
    test.extend((h, jiba))
ek = []
zt = []
for de in test:
    if type(de) == str:
        ek.append(de)
    elif type(de) == int:
        zt.append(de)
wuhan = {}
for y in range(len(ek)):
    wuhan[ek[y]] = zt[y]
openedFile.close()


def import_inventory():  # This function will create a dictionary of the inventory information.
    whole = []
    openedFile = open("products.txt")
    for line in openedFile:
        line = line.lower().strip()
        whole.append(line.split("-"))
    x = []
    for i in whole:
        for l in i:
            x.append(l.split("_"))
    items = {}
    for s in x:
        for m in s:
            if m.isdigit() == False and m not in items:
                items[m] = 0
    wubba = []
    for p in x:
        for f in p:
            wubba.append(f)
    test = []
    for h in items:
        jiba = 0
        for c in range(len(wubba)):
            if h == wubba[c]:
                jiba += int(wubba[c + 1])
        test.extend((h, jiba))
    ek = []
    zt = []
    for de in test:
        if type(de) == str:
            ek.append(de)
        elif type(de) == int:
            zt.append(de)
    wuhan = {}
    for y in range(len(ek)):
        wuhan[ek[y]] = zt[y]
    openedFile.close()


def sell_product(products):  # This function which will recalculate the remaining stock in the inventory.
    sold = input("Please enter products to sell: ")
    ns = sold.lower().split("-")
    prdcts = []
    for prod in ns:
        prdcts.append(prod.split("_"))
    for ui in prdcts:
        for des in range(len(ui)):
            if ui[des].isdigit() == False:
                if ui[des] in wuhan and wuhan[ui[des]] >= int(ui[des + 1]):
                    wuhan[ui[des]] -= int(ui[des + 1])
                    print(ui[des + 1], ui[des], "sold.")
                elif ui[des] not in wuhan:
                    print(ui[des], "does not exist in inventory.")
                elif int(ui[des + 1]) > wuhan[ui[des]] and wuhan[ui[des]] != 0:
                    print("There is not enough", ui[des], "in inventory.")
                elif wuhan[ui[des]] == 0:
                    print(ui[des], "does not exist in inventory.")

def show_remaining(products):  # This function to display the remaining stock in the inventory.
    import_inventory()
    for mama in sorted(wuhan):
      if wuhan[mama] == 0:
        del wuhan[mama]
    if len(wuhan) != 0:
      for key in sorted(wuhan):
          print(key, ":", wuhan[key])
    elif len(wuhan) == 0:
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
