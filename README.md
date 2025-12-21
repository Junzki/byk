# byk (Book)

A simple book manager.

## Usage

### Run API Server

Please make sure to run API server in async mode.  
The dev server (`django manage.py runserver`) is already integrated with async support with Daphne.


### Run Task Worker

```bash
faststream run byk.task_broker:app
```

## Requirements
- Python 3.12+
- PostgreSQL 14+
- Redis 7+

Please see [requirements](requirements.txt) for detail.


## License
This project is licensed under the **GNU General Public License v3 (GPLv3)**.

### Third-party Component Notices
The module `/nlc_isbn` contains code derived from [DoiiarX/NLCISBNPlugin](https://github.com/DoiiarX/NLCISBNPlugin) 
(Apache License 2.0). 
In accordance with the Apache 2.0 license, all original copyright notices are preserved, 
and modifications are documented. 
As a derivative work, this module is distributed under the GPLv3 license.