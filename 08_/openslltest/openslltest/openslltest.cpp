// openslltest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。


#include <iostream>
#include<string>
#include<openssl/sha.h>
#include<openssl/rsa.h>
#include<openssl/pem.h>
#include<openssl/aes.h>


extern "C"
{
#include <openssl/applink.c>
};

using namespace std;

void shalTest()
{	
	//初始化
	SHA_CTX ctx;
	SHA1_Init(&ctx);
	//加数据
	SHA1_Update(&ctx, "hello", strlen("hello"));
	SHA1_Update(&ctx, "fuck", strlen("fuck"));
	unsigned char* md = new unsigned char[SHA_DIGEST_LENGTH];
	 char* res = new  char[SHA_DIGEST_LENGTH*2+1];
	// 哈希计算
	SHA1_Final(md,&ctx);
	for (int i = 0; i < SHA_DIGEST_LENGTH;i++) {
		sprintf(&res[i*2],"%02x",md[i]);

	}

	cout << "sha1 1 : " << res << endl;

}

void genKey()
{
	RSA* rsa = RSA_new();
	BIGNUM* e=BN_new();
	BN_set_word(e, 12345);

	RSA_generate_key_ex(rsa,1024,e,NULL);

	FILE* fp = fopen("pub.pem","w");
	PEM_write_RSAPublicKey(fp,rsa);
	fclose(fp);
	fp = fopen("priv.pem", "w");
	PEM_write_RSAPrivateKey(fp,rsa,NULL,NULL,0,NULL,NULL);
	fclose(fp);


}

string encrpPublickey( )
{
	string text = "GG bao";
	
	FILE* fp = fopen("pub.pem", "r");
	RSA* pubkey = RSA_new();
	RSA* ret1 = RSA_new();
	ret1 = PEM_read_RSAPublicKey(fp,&pubkey,NULL,NULL);
	if (ret1 = NULL) {
		cout << "读取公钥 err" << endl;
	}
	fclose(fp);
	int keylen = RSA_size(pubkey);
	char *buf = new char[keylen];
	int len = RSA_public_encrypt(text.size(),(const unsigned char *)text.data(),
		(unsigned char*)buf,pubkey,RSA_PKCS1_PADDING);
	return string(buf, len);
}

string decrpPublickey(string buf1)
{
#if 0
	string text = "GG bao";
	FILE* fp = fopen("pub.pem", "r");
	RSA* pubkey = RSA_new();
	pubkey = PEM_read_RSAPublicKey(fp, &pubkey, NULL, NULL);
	fclose(fp);
	char *buf = new char[128];
	RSA_public_encrypt(text.size(), (const unsigned char *)text.data(),
		(unsigned char*)buf, pubkey, RSA_PKCS1_PADDING);
	return (string)buf;
#endif
	//读取私钥
	FILE* fp = fopen("priv.pem", "r");
	RSA* prikey = RSA_new();
	RSA* ret1 = RSA_new();
	ret1 = PEM_read_RSAPrivateKey(fp, &prikey, NULL,NULL);
	if (ret1 = NULL) {
		cout << "读取私钥 err" << endl;
	}
	fclose(fp);
	// 私钥解密
	int keylen = RSA_size(prikey);
	char *buf = new char[keylen];
	int len =RSA_private_decrypt(buf1.size(),(const unsigned char *)buf1.data(),
		(unsigned char *)buf, prikey, RSA_PKCS1_PADDING);

	return string(buf,len);
}

//签名和校验
void sig()
{
	//签名数据
	string text = "djjjj";
	RSA *pubkey = RSA_new();
	RSA *prikey = RSA_new();
	BIO* pubbio = BIO_new_file("pub.pem", "r");
	BIO* pribio = BIO_new_file("priv.pem", "r");
	PEM_read_bio_RSAPublicKey(pubbio, &pubkey, NULL, NULL);
	PEM_read_bio_RSAPrivateKey(pribio, &prikey, NULL, NULL);
	BIO_free(pubbio);
	BIO_free(pribio);
	
	int len = RSA_size(prikey);
	unsigned int outlen = 0;
	unsigned char* out = new unsigned char[len];
	RSA_sign(NID_sha,(const unsigned char*)text.data(),
		text.size(),out,&outlen,prikey);
	string sbuf((char*)out, outlen);
	string out1;
	int ret = RSA_verify(NID_sha, (const unsigned char *)text.data(), text.size(),
		(const unsigned char *)sbuf.data(), sbuf.size(), prikey);
	if (1 == ret) {
		cout << "sucess" << endl;
	}
	else {
		cout << "err" << endl;
	}

}

//测试对称加密

void aes()
{
	//准备数据
	const char* pt = "你说的对，但是《烟神》是由丁真珍珠自主研发的一款全新开放世界冒险游戏。游戏发生在一个被称作「理塘」的幻想世界，在这里被神选中的人将被授予「电子烟」，引导尼古丁之力。你将扮演一位名为「芙蓉王」的神秘角色，在自由的旅行中邂逅性格各异";
	//准备密钥
	const char* key = "1234567887654321";
	//初始化密钥
	AES_KEY enckey;
	AES_set_encrypt_key((const unsigned char*)key,128,&enckey);
	//加密
	int length = 0;
	int len = strlen((char*)pt) + 1;
	if (len %16 !=0) {
		length = ((len / 16) + 1)*16;
	}
	else {
		length = len;
	}
	unsigned char *out1 = new unsigned char[length];

	unsigned char *ivec = new unsigned char[AES_BLOCK_SIZE];
	memset(ivec,8,sizeof(ivec));
	
	AES_cbc_encrypt((const unsigned char*)pt, out1,
		length, &enckey,
		ivec, AES_ENCRYPT);

	//解密
	//初始化解密密钥

	AES_KEY dekey;
	AES_set_decrypt_key((const unsigned char*)key, 128, &dekey);
	unsigned char *data = new unsigned char[length];
	
	unsigned char *ivec2 = new unsigned char[AES_BLOCK_SIZE];
	memset(ivec2, 8, sizeof(ivec2));
	AES_cbc_encrypt(out1,data ,
		length, &dekey,
		ivec2, AES_DECRYPT);
	
	cout << "+++++++ "<< data << endl;
	//delete[]out1;
	//delete[]ivec;
	//delete[]data;

}


int main()
{
	//shalTest();
	//genKey();
	string data1;
	string data2;
#if 0
	data1 = encrpPublickey();
	data2 = decrpPublickey(data1);
	cout << "test is " <<data2<< endl;
	sig();
#endif
	aes();
	cout << "11111"<< endl;
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
