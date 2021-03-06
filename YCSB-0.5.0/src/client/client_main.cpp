#include "Client.h"
#include "cmdline.h"


int main(int argc, char *argv[]) {

    cmdline::parser parser;
    parser.add<std::string>("trx_type", 't', "transaction type", true, "");
    parser.add<std::string>("com_type", 'c', "communication type", true, "");
    parser.add<int>("write_trx_num", 'w', "num of write transactions", true, 0);
    parser.add<int>("read_trx_num", 'r', "num of read transactions", true, 0);
    parser.add<int>("data_num", 'n', "num of data", false, 100);
    parser.add<int>("trx_len", 'l', "transaction size (operations)", false, 8);
    parser.add<int>("value_size", 'v', "value size (bytes)", false, 1000);
    parser.parse_check(argc, argv);

    Config& config = Config::get_config();
    config.init();

    std::string trx_type = parser.get<std::string>("trx_type");
    if (trx_type == "rr" ) {
        config.trx_type = TrxType::LOCK_BASED;
    } else if (trx_type == "rc") {
        config.trx_type = TrxType::LOCK_BASED;
    } else if (trx_type == "ru") {
        config.trx_type = TrxType::LOCK_BASED;
    } else if (trx_type == "no_cc") {
        config.trx_type = TrxType::NO_CONCURRENCY_CONTROL;
    } else if (trx_type == "ramp_f") {
        config.trx_type = TrxType::RAMP_FAST;
    } else if (trx_type == "ac_ramp_f") {
        config.trx_type = TrxType::AC_RAMP_FAST;
    } else {
        printf("Unkown Trx_Type\n");
        exit(1);
    }

    std::string com_type = parser.get<std::string>("com_type");
    if (com_type == "tcp") {
	config.com_type = ComType::TCP;
    } else if (com_type == "ipoib") { 
	config.com_type = ComType::IPoIB;
    } else if (com_type == "send_recv") {
	config.com_type = ComType::SEND_RECV;
    } else if (com_type == "rdma_write") { 
	config.com_type = ComType::RDMA_WRITE;
    } else if (com_type == "rdma_write_imm") { 
	config.com_type = ComType::RDMA_WRITE_IMM;
    } else {
	printf("Unkown Communication Type\n");
	exit(1);
    }
    
    config.data_num = parser.get<int>("data_num");
    config.worker_num = 8;
    config.trx_len = parser.get<int>("trx_len");
    config.write_trx_num = parser.get<int>("write_trx_num");
    config.read_trx_num = parser.get<int>("read_trx_num");
    config.trx_num = config.write_trx_num + config.read_trx_num;
    config.value_size = parser.get<int>("value_size");
    config.read_server_list();
    config.sleep_flag = true;
    config.sleep_time = {0, 100};
    
    Client client;
    
    client.start_all();
    client.check_finish();
    client.print_result();

    return 0;
}
