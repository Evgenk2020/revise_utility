# revise_utility for Buildroot virtual x86

<p>Утилита для проверки наличия обновлений stable и beta</p>

  >1. Скопировать содержимое каталога <b>revise</b> в <b>package</b>
  >2. В файл <b>Config.in</b> каталога <b>package</b> внести запись -
  ><i>source "package/revise/Config.in"</i>
  >3. Для интеграции пакета необходимо включить библиотеки <b>libcurl</b> и <b>rapidjson</b> в
  >настройках make <b>nconfig</b>
  >
