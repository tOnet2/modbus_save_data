<h1>Reading and inserting modbus registers into the mysql database</h1>
<p>Simple program that run as daemon</p>
<p>While it is running as loop, reading data from modbus tcp and inserting data into mysql database</p>
<p>Used libmodbus and libmysqlcppconn</p>
<p><i>config file - src/config.h</i></p>

<b>
<p>Before you start, you need four tables:</p>
<p></p><b>create table</p>
<p>(input_coils, output_coils, input_holdings, output_holdings)</p>
<p>(</p>
<p>start smallint unsigned not null,</p>
<p>amount smallint unsigned not null,</p>
<p>data varbinary(256) not null,</p>
<p>id bigint unsigned auto_increment primary key,</p>
<p>dt datetime default current_timestamp()</p>
<p>);</p>
</b>

<p>Example of memory used.</p>
<p><i>100 registers from i/o c/h every hour = (100b + 100b + 200b + 200b) * 24h * 366d = 5 270 400 bytes every year, hehe</i></p>
