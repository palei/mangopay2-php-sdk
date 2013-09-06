<?php
namespace MangoPay;
require_once __DIR__ . '/common/common.inc';

/**
 * MangoPay API main entry point.
 * Provides managers to connect, send and read data from MangoPay API
 * as well as holds configuration/authorization data.
 */
class MangoPayApi {
    
    /////////////////////////////////////////////////
    // Config/authorization related props
    /////////////////////////////////////////////////

    /**
     * OAuthToken
     * @var \MangoPay\OAuthToken
     */
    public $OAuthToken;

    /**
     * Configuration instance
     * @var \MangoPay\Configuration
     */
    public $Config;
    
    /////////////////////////////////////////////////
    // API managers props
    /////////////////////////////////////////////////

    /**
     * OAuth methods
     * @var ApiOAuth
     */
    public $AuthenticationManager;

    /**
     * Clients methods
     * @var Client 
     */
    public $Clients;
    
    /**
     * Users methods
     * @var ApiUsers 
     */
    public $Users;
    
    /**
     * Wallets methods
     * @var ApiWallets
     */
    public $Wallets;
        
    /**
     * Transfers methods
     * @var ApiTransfers
     */
    public $Transfers;
    
    /**
     * Pay-in methods
     * @var ApiPayIns 
     */
    public $PayIns;
    
    /**
     * Pay-out methods
     * @var ApiPayOuts 
     */
    public $PayOuts;
        
    /**
     * Refund methods
     * @var ApiRefunds 
     */
    public $Refunds;

    /**
     * Constructor
     */
    function __construct() {

        // default config setup
        $this->Config = new Configuration();
        if (defined('MangoPay_ClientId')) {
            $this->Config->ClientId = MangoPay_ClientId;
        }
        if (defined('MangoPay_ClientPassword')) {
            $this->Config->ClientPassword = MangoPay_ClientPassword;
        }
        if (defined('MangoPay_BaseUrl')) {
            $this->Config->BaseUrl = MangoPay_BaseUrl;
        }

        // API managers
        $this->AuthenticationManager = new ApiOAuth($this);
        $this->Clients = new ApiClients($this);
        $this->Users = new ApiUsers($this);
        $this->Wallets = new ApiWallets($this);
        $this->Transfers = new ApiTransfers($this);
        $this->PayIns = new ApiPayIns($this);
        $this->PayOuts = new ApiPayOuts($this);
        $this->Refunds = new ApiRefunds($this);
    }
}