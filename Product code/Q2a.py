
def getPartsInCode(productCode: str) -> str:
  count = 0
  resultString = ""
  temp = productCode[0]
  for itr in productCode:
    if itr == temp:
      count += 1
    else:
      resultString = resultString + str(count) + temp + " "
      temp = itr
      count = 1
  resultString = resultString + str(count) + temp + " "
  return resultString.rstrip()

if __name__ == "__main__":
  print(getPartsInCode("AACCDDDDLLLLLL"))
  asd = getPartsInCode("AACCDDDDLLLLLL")
  print(asd)
  print(asd.split(" "))