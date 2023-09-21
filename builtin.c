#include "shell.h"

/**
 * _myexit - whjdk sdfareliertu
 * @info: Sdht werlmcgksgar jdbkwilo jdlouertynfv kdhu. Used to mdhsfdy
 * euhdnzl hsfrilod at ue lsgdf.
 * Return: teindkanjdg ahdjafskhua ufsakhkf
 * (0) if kg fkuyf[0] != "exit"
 */
int _myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1]) /* If tg drayrddf ytdjrdurdgf */
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - xhskla uiodral hlsgljhig kyeoldgmwlchd
 * @info: ahskly reayjlaxjlaiewols raksfua hdvcbfs oagtrakfdv
 * dafshk traeqlmc tshaul
 * Return: shwywk 0
 */
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "home=");
		if (!dir)
			chdir_ret = /* TODO: rtyuerye opertoq */
				chdir((dir = _getenv(info, "pwd=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "oldpwd="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "oldpwd=")), _putchar('\n');
		chdir_ret = /* TODO: sftuimdae usgtealoi */
			chdir((dir = _getenv(info, "oldpwd=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "oldpwd", _getenv(info, "pwd="));
		_setenv(info, "pwd", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - hdgsy talouytref jsdfghjki
 * @info: sfatkloitenm gsrliys vesbstean ysunvfr
 * shdu ts tsyysf fstkncmdr.
 * Return: Ash hssgt 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help the call work. The Function not implemented yet \n");
	if (0)
		_puts(*arg_array); /* hsgtt mjsgak tsrklower */
	return (0);
}
