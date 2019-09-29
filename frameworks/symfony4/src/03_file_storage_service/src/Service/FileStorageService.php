<?php


namespace App\Service;


use Monolog\Logger;
use Symfony\Component\Filesystem\Filesystem;

class FileStorageService implements FileStorageServiceInterface
{
    protected $fs;

//    protected $logger;

    protected $filename;

    protected $directory;

    public function __construct(Filesystem $fs, string $directory, string $filename)
    {
        $this->fs = $fs;

//        $this->logger = $logger;

        $this->directory = $directory;

        $this->filename = $filename;

        //Ignores existing directories
        $this->fs->mkdir($this->directory);
    }

    protected function getFullPath(): string
    {
        $separator = substr($this->directory, -1) === DIRECTORY_SEPARATOR ? '' : DIRECTORY_SEPARATOR;
        return sprintf('%s%s%s', $this->directory, $separator, $this->filename);
    }

    protected function getDescriptor(int $operation)
    {

        if (!is_writable($this->directory)) {
            throw new \Exception(sprintf('The directory "%s" is not writable', $this->directory));
        }

        if (!$df = fopen($this->getFullPath(), 'c+')) {
            throw new \Exception(sprintf('Can not open the file "%s"', $this->getFullPath()));
        }

        if (!flock($df, $operation)) {
            throw new \Exception(sprintf('Can not lock the file "%s"', $this->getFullPath()));
        }

        return $df;
    }

    protected function closeDescriptor($df): void
    {
        flock($df, LOCK_UN);
        fclose($df);
    }

    public function getContent(): array
    {

        $df = $this->getDescriptor(LOCK_SH);
        $json = '';

        while (($string = fgets($df, 4096)) !== false) {
            $json .= $string;
        }

        $this->closeDescriptor($df);

        return json_decode($json, true) ?? [];
    }

    public function setContent(array $content): void
    {
        $df = $this->getDescriptor(LOCK_EX);

        if (fwrite($df, json_encode($content)) === FALSE) {
            throw new \Exception(sprintf('Can not write to the file "%s"', $this->getFullPath()));
        }

        $this->closeDescriptor($df);
    }
}