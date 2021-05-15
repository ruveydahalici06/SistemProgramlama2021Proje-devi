#GRUP ELEMANLARI - Görevleri
	B171210046 - Rüveyda Halıcı - Proje Yöneticisi
	B171210055 - Emre Demir - Deployment Sorumlusu
	B181210001 - Ayberk Köse - Json formatındaki kilit dosyasının okunması
	B171210034 - Burak Çevik - Encode ve decode işlemlerinin yapılması

#ÖZET
	Program, verilen anahtara ve terminalden girilen işlem çeşidine göre giriş metnini şifreli ise şifresini çözmekte, şifreli değil ise şifrelemektedir. Kilit dosyasında her kelimenin karşılığı vardır. Karşılığı olmayan kelimeler, şifreleme ve şifre çözme işlemine tabi tutulmadan çıkışa aktarılmaktadır. Kilit dosyası JSON formatındadır. Veri yapısı olarak Red Black Tree kullanılmaktadır.
	
#PROJE ÇALIŞMASI
Projeyi derlemek için iki yöntem vardır. Bu yöntemlerden ilki terminale
			>> make run 
komutunun girilmesidir. Bu komut ilk olarak önceden oluşturulmuş .o dosyalarını ve çalıştırılabilir dosyayı siler. Ardından make komutu ile projeyi derler. Bu işlem oluşturduğumuz kütüphaneleri ve libfdr kütüphanelerini birleştirerek çalıştırılabilir dosyayı oluşturur. Libfdr kütüphanesini projeye dahil etmek için ön derlenmiş libfdr.a dosyası kullanılmaktadır. Projede libfdr kütüphanesi tekrar derlenmemektedir. 

Bu işlemde terminalden giriş ve çıkış dosya isimleri alınmaz. Klasörde mevcut olan .kilit isimli JSON formatındaki dosya ve ornek_metin isimli giriş dosyasını kullanarak önce şifreleme işlemi gerçekleştirilir ve "encrypted" isimli dosya oluşturulur. Ardından "encrypted" isimli dosyanın şifresi çözülür ve şifresi çözülmüş veriler "decrypted" isimli dosyaya aktarılır.  
	
İkinci yöntem ise projenin 
			>>make 
komutu ile derlenmesidir. Bu komut çalıştırılabilir dosyayı oluşturur. Programın düzgün bir şekilde çalışması için terminal parametreleri doğru girilmelidir. 

Şifreleme işlemi yapmak için;	
			>> ./kripto -e giris_metni cikis_metni			
formatında giriş yapılmalıdır. Bu komut JSON formatındaki kilit dosyasını okur ve kelime-kod ikilisini ağaca key-value şeklinde yerleştirir. Daha sonra giriş metnindeki her bir kelime okunur ve ağaçta karşılığı var mı diye bakılır. Okunan kelimenin ağaçta karşılığı olan kod değeri çıkış dosyasına yazılır. Eğer giriş dosyasından okunan kelime ağaçta yok ise kelime şifrelenmeden çıkış dosyasına yazılır. Her bir kelime için bu işlem yapıldığında şifreleme işlemi tamamlanır.
	
Şifre çözme işlemi yapmak için;
			>> ./kripto -d sifrelenmis_metin cikis_metni
formatında giriş yapılmalıdır. Bu komut JSON formatındaki kilit dosyasını okur ve kelime-kod ikilisini ağaca value-key şeklinde yerleştirir. Daha sonra sifrelenmiş giriş metnindeki her bir kod okunur ve ağaçta karşılığı var mı diye bakılır. Okunan kodun ağaçta karşılığı olan kelime çıkış dosyasına yazılır. Eğer şifrelenmiş metin dosyasından okunan kod ağaçta yok ise kod direkt çıkış dosyasına yazılır. Her bir kod için bu işlem yapıldığında şifre çözme işlemi tamamlanır.

#DİĞER KOMUTLAR
		>>make clean
Çalıştırılabilir dosyayı ve tüm obje dosyalarını siler.

		>>make cleanall
Çalıştırılabilir dosya, giris, çıkış metinleri, .kilit dosyası ve tüm obje dosyalarını siler.

#BİLİNEN HATALAR VE EKSİK KISIMLAR
Proje tüm isterleri karşılamaktadır. 
