import random
a = 5#int(input("Enter the geight value: "))
for i in range(1,a+1):
    print("O"*i)
print("----------------------------")
for m in range(0,a):
    print(" "*(a-m-1)+ "O"* (2*m+1))
print("----------------------------")
for k in range(0,a):
    print(" " * k+"O" * (2*a-2*k-1))
studentNames = [
	'Yahsi, Fatih Taha',
	'Karabaglı, Batuhan',
	'Karaev, Timur',
	'Egeli, Rukiye-ayshe',
	'Unal, Berfe Naz',
	'Rzayev, Murad',
	'Yetki, Tan Doruk',
	'Ridwan Kudret , Syed',
	'Babazade, Heydar',
	'Bashirli, Sevinj',
	'Saygın, Ali',
	'Ahad, Abdul',
	'Sekerci, Sumeyye Dilara',
	'Asif, Maria',
	'Karman, Husam Addın',
	'Musayev, Nihad',
	'Zakaria, Ali',
	'Elyakubi, Emin',
	'Rafi, Ramza',
	'Zaim, Chaimaa',
	'Kassem, Abdelrahman',
	'Boy, Navruz Yusuf',
	'Kılıc, Ipek',
	'senturk, Cihan',
	'Erdem, Kadir Kagan',
	'Dogan, Eliz',
	'Yılmaz, Selcuk',
	'Kahraman, Dua Kayra',
	'sener, Ozkul Emre',
	'Turkbayragı, Deniz',
	'Altunbag, Muharrem',
	'Kayan, Berke',
	'Kucukahmetler, Deniz',
	'Caglayan, Cemre',
	'Caniklioglu, Serkan Bekir',
	'Ongun, Alp',
	'Salkaya, Zeynep',
	'Arslan, Yeraz',
	'Kok, Tahsin Altay',
	'Tınaz, Leyla',
	'Karal, Bora Mert',
	'Erdemli, Volkan',
	'Dokgoz, Alp',
	'Karacan, Irem',
	'Yaradanakul, Zeynep',
	'Beyaztas, Dorukhan',
	'Seven, Elif',
	'Zeki, Ipek',
	'Abacı, Dorukan',
	'Ozkan, Halil Armagan',
	'Erdem, Okyanus',
	'Karabulut, Eylul Berfin',
	'Palakcı, Zeynep',
	'Circi, Defne',
	'Okanoglu, Bora',
	'Kaya, Burak',
	'Demirci, Bengisu',
	'Tozkoparan, Arda',
	'Mazıcı, Bengisu',
	'Binici, Gozde',
	'Koyuncu, Kerem',
	'Omur, Ceyda',
	'Gonenc, Sude Sena',
	'Olgun, Yigit Ruzgar',
	'Akyol, Yasemin',
	'Ogmen, Ayse Esra',
	'Turna, Ceren',
	'Balcı, Ilayda',
	'Oflaz, Gurhan Barkın',
	'Celebi, Ceren',
	'Cetin, Barıs Ege',
	'Kahraman, Beste',
	'sener, Yaman',
	'Aksit, Mehmet Cevat',
	'Ozmen, Aysegul',
	'Eryuksel, Esin',
	'Zengin, Burcu',
	'Kutsal, Arda',
	'Cankaya, Semih Polat',
	'Havuz, Sena Naz',
	'Sozer, Ugur Dogan',
	'Akant, Zeynep',
	'Kurtaran, Ali',
	'Savaskan, Emir',
	'Mevlat, Dante Yetvart',
	'Tufekci, Zeynep',
	'Tuzlen, Serra',
	'Ozoral, Elif Yesim',
	'sahin, Can',
	'Bekar, Zeynep',
	'sahsuvaroglu, Algan',
	'Ovun, Ece',
	'Baydar, Tolga',
	'Telli, Ceyda',
	'Akpınar, Dorukhan',
	'Coskun, Giray',
	'Aykanat, Cicek Nur',
	'Ucal, Gizem',
	'Nuhoglu, Ozgur',
	'Kılınc, Zeynep',
	'Ogurlu, silan',
	'Ozcelik, Ece',
	'Ozyoran, Ozlem',
	'Sıradag, Arda',
	'Sabah, Berke Kagan',
	'Arıgumus, Ahmet Emre',
	'Ersoy, Hatice Elif',
	'Erturk, Gozde',
	'Ozteber, Ege Yusuf',
	'Temucin, Elif sevval',
	'Ciftcioglu, Pelinsu',
	'Silahyurekli, Osman Serhan',
	'Aga, Firuze Alinda',
	'Balın, Talha',
	'Korkmazgil, Buse Nur',
	'Ergezer, Ece',
	'Kaya, Berdan Lal',
	'Ozbil, Mazhar Mert',
	'Albayrak, Oyku',
	'Okan, Kerem',
	'Arslan, Karya Ceren',
	'senol, Irmak',
	'Kula, Nur Aslısah',
	'Aya, Ecem Meva',
	'Yavuz, Oguz Kagan',
	'Altug, Selin',
	'Ergun, Mert',
	'Umucu, Zeynep',
	'Basar, Aslı Sinem',
	'Mutlu, Eren',
	'Kutman, Buse',
	'Geron, Sinan Sami',
	'Tercan, Murat',
	'Mustecep, Dilara',
	'Seckin, Elif Nur',
	'Onar, Eylul',
	'Malaz, Mert',
	'Turhan, Berk',
	'Erdogan, Ege',
	'Cinar, Hasan Ertugrul',
	'Elbası, Burcu',
	'Duran, Cagla Sıla',
	'Sipahioglu, Faruk',
	'Sakallı, Irem',
	'Aydın, Mustafa Bora',
	'Yurudur, Mehmet Berkay',
	'Koc, Deniz',
	'Aykac, Deniz',
	'Ozerli, Ahmet sevki',
	'Kaya, Kerem',
	'Deniz, Ahmet Tarık',
	'Habiboglu, Yamac',
	'Akalın, Cahit Batu',
	'Yalcın, Mehmet Yavuz',
	'Bayrakcı, Zeynep Lara',
	'Sozugur, Bedia Deniz',
	'Cosar, Olgu Cagın',
	'Pekel, Ege Deniz',
	'Coruh, Simay',
	'Ferah, Cengiz Kaan',
	'Tamer, Can',
	'Duran, Emre Aykut',
	'Cangı, Deniz',
	'Gover, Mehmet Yigit',
	'Sumer, Aleyna Buse',
	'Ozen, Mebrure Buket',
	'Celik, Erdem Ulas',
	'Karaosmanoglu, Ece',
	'Ak, Merve',
	'Yuksel, Ecem',
	'Ozturk, Zeynep Serra',
	'Gucin, Nilay Irem',
	'Celik, Dogancan',
	'Mete, Sabanur',
	'Inmez, Can Arman',
	'Yelmen, Deren',
	'Derya, Sevgi Sumru',
	'Manay, Selin',
	'Kocaman, Orcun',
	'Sezgin, Mehmet Berke',
	'Kerestecioglu, Alihan',
	'Izgi, Kuzey',
	'Erdem, Ece',
	'Erkotuz, Gokce Naz',
	'Oncel, Mert',
	'Guler, Deniz',
	'Kopru, Bengisu',
	'Bilgin, san Batu',
	'Yılmaz, Mert',
	'Caner, Turan Ege',
	'Kurumahmutoglu, Yaren Dila',
	'Keklik, Hasan',
	'Gorur, Ali Kerem',
	'Karabulut, Nazire',
	'Sunar, Nilufer',
	'sen, Omer Efe',
	'Akyuz, Cosku',
	'Baghırov, Musa',
	'Mehdiyev, Maqsud',
	'Ibishova, Melissa',
	'Ezzaim, Mohamed Yassine',
	'Yildirim, Deniz',
	'Tansu, Berke',
	'Oz, Remzi Yigit'
]
print(len(studentNames))
idList = []
for i in range(random.randint(1,len(studentNames))):
    if random.randint(24756, 25659) not in idList:
        idList.append(random.randint(24756, 25659))
for m in range(len(idList)):
    print(studentNames[random.randint(0,203)],idList[m])
products = ["Origin", "Kördüğüm", "Sen Kimsin?", "Anlatsam Geçer mi?", \
            "Korkma! İyi bir Annesin", "Sapiens", "Güzel Kaybettik", \
            "Seher", "Sen Kimsin?",  "Korkma! İyi bir Annesin", "Sapiens", \
            "Korkma! İyi bir Annesin", "Sen Kimsin?", "Kördüğüm", "Kördüğüm", \
            "Sen Kimsin?", "Seher", "Kördüğüm", "Korkma! İyi bir Annesin"]
nonDup = []
for i in products:
    if products.count(i) == 1:
        nonDup.append(i)
print(nonDup)

k = input("Enter a string: ")
occurances = []
dup = []
heh = []
for i in range(len(k)):
    occurances.extend((k[i], k.count(k[i])))

while k.lower() != "exit":
    k = input("Enter a string: ")
    for i in range(len(k)):
        occurances.extend((k[i],k.count(k[i])))
        if type(k[i]) == str and k[i] not in dup:
            dup.append(k[i])
for m in dup:
  ticket = 0
  for i in range(len(occurances)):
    if m == occurances[i]:
      ticket += int(occurances[i + 1])
  heh.extend((m , ticket))
r = 1
print(heh)
indx = []
for i in heh:
	if type(i) == int:
		indx.append(i)

maxIndex = indx.index(max(indx))
print(indx)
print(heh[maxIndex*2], "->",indx[maxIndex])

