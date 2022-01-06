# revise_utility for Buildroot virtual x86

<p>Утилита для проверки наличия обновлений stable и beta</p>

  >1. Скопировать содержимое каталога <b>revise</b> в <b>package</b>
  >2. В файл Config.in каталога package внести запись -
  >source "package/revise/Config.in"
  >3. Для интеграции пакета необходимо включить библиотеки libcurl и rapidjson в
  >настройках make nconfig
  >
