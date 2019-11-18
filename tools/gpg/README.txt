
//import someone's public key
gpg --import name_of_pub_key_file



//gpg key server
https://pgp.mit.edu/

//search key on server by parameters
gpg --keyserver pgp.mit.edu  --search-keys search_parameters

//get the fingerprint of a public key
gpg --fingerprint info@spendmail.ru
    pub   rsa2048 2019-11-15 [SC]
          37B4 20AE 0BAF 6140 9DCC  ED1B DF9E 64FE 6726 9405
    uid         [  абсолютно ] spendmail <info@spendmail.ru>
    sub   rsa2048 2019-11-15 [E]

//sign someone key
//подписывание ключа говорит,
//что вы доверяете ключу, который вам предоставлен,
//и вы подтвердили, что он связан с конкретным лицом
gpg --sign-key email@example.com

//export signed key back to user
gpg --output ~/signed.key --export --armor email@example.com

//import of signed key
gpg --import ~/signed.key


//export my public key
gpg --output ~/mygpg.key --armor --export your_email@address.com

//another my public key to key server
gpg --list-keys
gpg --send-keys --keyserver pgp.mit.edu pub_key_id

//encrypt message
//using the recipient’s public key
//and signs it with your own private key (guarantee that it is coming from you)
gpg --encrypt --sign --armor -r person@email.com name_of_file

//decrypt message
gpg file_name.asc
//in case of getting a raw text stream
//gpg <put_it_here> ctrl+d


//useful commands
gpg --list-keys
//update info about revoked keys
gpg --refresh-keys
//pull information from a specific key server
gpg --keyserver key_server --refresh-keys



