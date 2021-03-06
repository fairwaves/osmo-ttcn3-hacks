
/* Utility functions that I'm used to from C but for which I couldn't find TTCN-3 implementations
 *
 * (C) 2017 by Harald Welte <laforge@gnumonks.org>
 */

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <Charstring.hh>
#include <Octetstring.hh>

namespace Native__Functions {

OCTETSTRING f__inet6__addr(const CHARSTRING& in)
{
	char buf[INET6_ADDRSTRLEN];
	TTCN_Buffer ttcn_buffer(in);
	int ret;

	ret = inet_pton(AF_INET6, (const char *)ttcn_buffer.get_data(), buf);
	if(ret < 1)
		fprintf(stderr, "inet_pton failed: %d %s\n", ret, strerror(errno));

	return OCTETSTRING(16, (const unsigned char *)&buf[0]);
}

OCTETSTRING f__inet__addr(const CHARSTRING& in)
{
	TTCN_Buffer ttcn_buffer(in);
	in_addr_t ia;

	ia = inet_addr((const char *)ttcn_buffer.get_data());

	return OCTETSTRING(4, (const unsigned char *)&ia);
}

OCTETSTRING f__inet__haddr(const CHARSTRING& in)
{
	TTCN_Buffer ttcn_buffer(in);
	in_addr_t ia;

	ia = inet_addr((const char *)ttcn_buffer.get_data());
	ia = ntohl(ia);

	return OCTETSTRING(4, (const unsigned char *)&ia);
}

CHARSTRING f__inet__ntoa(const OCTETSTRING& in)
{
	TTCN_Buffer ttcn_buffer(in);
	const struct in_addr ia = *(const struct in_addr *)ttcn_buffer.get_data();
	const char *str = inet_ntoa(ia);

	return CHARSTRING(str);
}

CHARSTRING f__inet__hntoa(const OCTETSTRING& in)
{
	TTCN_Buffer ttcn_buffer(in);
	struct in_addr ia = *(const in_addr *)ttcn_buffer.get_data();
	ia.s_addr = htonl(ia.s_addr);
	const char *str = inet_ntoa(ia);

	return CHARSTRING(str);
}


} // namespace
