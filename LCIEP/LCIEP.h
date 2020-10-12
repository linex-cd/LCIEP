
/***********************************************************************/
/*                                                                     */
/*	Description: Linex custom IE Protocol Interface                    */
/*	Wrote by   : Linex                                                 */
/*	QQ         : 909090185                                             */
/*	E-mail     : www@loginar.com                                       */
/*	Update Data: 2012/11/27                                            */
/*                                                                     */
/***********************************************************************/
//////////////////////////////////////////////////////////////////////

#ifndef __LCIEP_H__
#define __LCIEP_H__

__declspec(dllimport) int CreateCIEP(LPCTSTR szProtocolName, LPCTSTR szProtocolApp);
__declspec(dllimport) int DeleteCIEP(LPCTSTR szProtocolName);
__declspec(dllimport) int CheckCIEP(LPCTSTR szProtocolName);


#endif