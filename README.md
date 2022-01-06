# revise_utility for Buildroot virtual x86

<p>Утилита для проверки наличия обновлений stable и beta</p>

  >1. Скопировать содержимое каталога <b>revise</b> в <b>package</b></br>
  >2. В файл <b>Config.in</b> каталога <b>package</b> внести запись -</br>
  ><i>source "package/revise/Config.in"</i>
  >3. Для интеграции пакета необходимо включить библиотеки <b>libcurl</b> и <b>rapidjson</b> в</br>
  >настройках <b>make nconfig</b>
