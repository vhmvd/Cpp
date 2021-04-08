from Q2a import getPartsInCode

def summarisedData() -> None:
  choice = input("0-restock, 1-make, 2-outstanding. Enter choice: ")
  if choice == "0":
    print("Summarised Data for RESTOCK ***")
    with open("transactions.txt", "r") as transactionFile:
      for line in transactionFile:
        splitLine = line.split(" ")
        if splitLine[0] == "restock":
          print(splitLine[1], splitLine[2])
  elif choice == "1":
    print("Summarised Data for MAKE ***")
    with open("transactions.txt", "r") as transactionFile:
      for line in transactionFile:
        splitLine = line.split(" ")
        if splitLine[0] == "make":
          print(splitLine[1], splitLine[2])
  elif choice == "2":
    print("Summarised Data for OUTSTANDING ***")
    with open("transactions.txt", "r") as transactionFile:
      for line in transactionFile:
        splitLine = line.split(" ")
        if splitLine[0] == "outsanding":
          print(splitLine[1], splitLine[2])
  else:
    print("\nInvalid choice\n")

def makeProduct(code: str, quantity: int, partLevel: list, partIds) -> None:
  parts = getPartsInCode(code)
  parts = parts.split(" ")
  count = 0
  for itr in range(0, quantity):
    flag = True
    for partsAndCount in parts:
      if int(partsAndCount[0]) <= partLevel[partIds.find(partsAndCount[1])]:
        continue
      else:
        flag = False
    if flag:
      count += 1
      for partsAndCount in parts:
        partLevel[partIds.find(partsAndCount[1])] -= int(partsAndCount[0])
    else:
      break
  
  if quantity == count:
    print(quantity, "product", code, "successfully made")
  else:
    print("Insufficient inventory.")
    print(count, "product", code, " made at the current inventory level.")
    print(quantity-count, "outstanding")
  with open("transactions.txt", "a") as transactionFile:
    if quantity == count:
      transactionFile.write("make " + str(code) + " " + str(quantity) + "\n")
    else:
      transactionFile.write("make " + code + " " + str(count) + "\n")
      transactionFile.write("outstanding " + str(code) + " " + str(int(quantity-count)) + "\n")

def codeAdded(codes: list, code: str) -> bool:
  for itr in codes:
    if code == itr:
      return True
  return False


def updateInventory(partLevel: list, partIds: str, selection: str, quantity: int) -> None:
  partLevel[partIds.find(selection.capitalize())] += quantity



def checkPartIdentifier(part: str, partIdentifier: str) -> bool:
  if part.capitalize() in partIdentifier:
    return True
  else:
    return False



def listInventory(productCodes: list, partLevel: list, reorderLimit: int) -> None:
  print("Part   Stock   Level")
  for productCode, level in zip(productCodes, partLevel):
    asterisk = ""
    if level <= reorderLimit:
      asterisk = "***"
    else:
      asterisk = ""
    print("{:5}{:5}{:>8}".format(productCode, level, asterisk))
  print("Legend: *** stock level at or lower than reorder point 20\n\n")



def checkProductCode(code: str, ID: str) -> bool:
  if len(code) < 3:
    return False
  for itr in code:
    if itr.capitalize() in ID:
      continue
    else:
      return False
  return True



def addProductCode(code: str, listOfCodes: list) -> None:
  if "".join(sorted(code.upper())) in listOfCodes:
    print("\nThe product code already exists\n")
  else:
    listOfCodes.append("".join(sorted(code.upper())))
    print("\nThe product code has been added successfully\n")
    print("\nNote that the code added is", "".join(sorted(code.upper())), "(sorted and in uppercase)\n")



def menu() -> str:
  print("Menu")
  print("1. Add product code")
  print("2. List inventory")
  print("3. Update inventory")
  print("4. Make product")
  print("5. Get summarized data")
  print("0. Exit")
  choice = input("INPUT: ")
  return choice

def main() -> None:
  startLevel   = 100
  reorderPoint = 20
  partIds      = "ABCDEFGHIJKL"
  partLevel    = []
  productCodes = []
  newCodes     = []
  for itr in partIds:
    partLevel.append(startLevel)
    productCodes.append(itr)
  while True:
    choice = menu()
    if choice == "1":
      productCodeInput = input("Enter product code: ")
      if checkProductCode(productCodeInput, partIds):
        addProductCode(productCodeInput, newCodes)
      else:
        print("\nThe product code is invalid\n") 

    elif choice == "2":
      listInventory(productCodes, partLevel, reorderPoint)

    elif choice == "3":
      while True:
        selection = input("Enter part identifier or <ENTER> to end: ")
        if selection == "":
          break
        if checkPartIdentifier(selection, partIds):
          print("Current stock level for", selection.capitalize(), "=", partLevel[partIds.find(selection)])
          quantity = int(input("Enter quantity to add: "))
          if quantity <=0:
            print("\nThe quantity is invalid\n")
          else:
            updateInventory(partLevel, partIds, selection.capitalize(), quantity)
            print("Updated stock level for", selection, "=", partLevel[partIds.find(selection)])
            with open("transactions.txt", "a") as transactionFile:
              transactionFile.write("restock " + str(selection.capitalize()) + " " + str(quantity) + "\n")
        else:
          print("\nThe part identifier is invalid\n")

    elif choice == "4":
      code = input("Enter product code: ")
      code = "".join(sorted(code.upper()))
      if checkProductCode(code, partIds):
        if codeAdded(newCodes, code):
          quantity = int(input("Enter quantity to make: "))
          if quantity <= 0:
            print("Invalid quantity", quantity)
          else:
            makeProduct(code, quantity, partLevel, partIds)
        else:
          print("Invalid product code", code)
      else:
        print("Invalid product code", code)

    elif choice == "5":
      summarisedData()
    elif choice == "0":
      return
    else:
      print("Invalid choice")

if __name__ == "__main__":
  main()